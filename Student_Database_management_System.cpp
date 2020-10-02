#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *fp,*ft;
    char another,choice;
    struct student
    {
        char first_name[50];
        char last_name[50];
        char course[100];
        char section;
    };
    struct student e;
    char xfirst_name[50],xlast_name[50];
    long int recsize;
    fp=fopen("users.txt","rb+");
    if(fp==NULL)
    {
        fp=fopen("users.txt","wb+");
        if(fp==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }
    recsize=sizeof(e);
    while(1)
    {
        system("cls");
        cout <<"\t\t=====Student Database Management System=====";
        cout << "\n\n";
        cout << "\t\t1. Add Records\n";
        cout << "\t\t2. List Records\n";
        cout << "\t\t3. Modify Records\n";
        cout << "\t\t4. Delete Records\n";
        cout << "\t\t5. Exit Program\n";
        cout << "\n\n";
        cout << "\t\tSelect Your Choice: ";
        fflush(stdin);
        choice=getche();
        switch(choice)
        {
        case '1':
            fseek(fp,0,SEEK_END);
            another='y';
            while(another=='y' || another=='Y')
            {
                cout << "\nEnter Your First Name: ";
                cin >> e.first_name;
                 cout << "\nEnter Your Last Name: ";
                cin >> e.last_name;
                 cout << "\nEnter Your Course Name: ";
                cin >> e.course;
                 cout << "\nEnter Your Section: ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\nAdd Another Record(Y/N): ";
                fflush(stdin);
                another=getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout << "\t===View the Recordds in the Database===";
            cout << "\n";
            while(fread(&e,recsize,1,fp)==1)
            {
                cout <<"NAME: " << e.first_name << setw(2) << e.last_name;
                cout << "\n";
                cout <<"COURSE: "<< e.course;
                cout << "\n";
                cout << "SEC: " << e.section << "\n";
            }
            cout << "\n";
            system("pause");
            break;
        case '3':
            system("cls");
            another='y';
            while(another=='y' || another=='Y')
            {
                cout << "Enter the first name of the student: ";
                cin >> xfirst_name;
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.first_name,xfirst_name)==0)
                    {
                        cout << "\nEnter new first name";
                        cin >> e.first_name;
                        cout << "\nEnter new Last name";
                        cin >> e.last_name;
                        cout << "\nEnter new course name";
                        cin >> e.course;
                        cout << "\nEnter new section";
                        cin >> e.section;
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout << "\nRecord not found\n";
                }
                cout << "Modify another record(Y/N): ";
                fflush(stdin);
                another=getchar();
            }
            break;
        case '4':
            system("cls");
            another='y';
            while(another='y' || another=='Y')
            {
                cout << "\nEnter the first name of the student to delete: ";
                cin >> xfirst_name;
                ft=fopen("temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(xfirst_name,e.first_name)!=0)
                        fwrite(&e,recsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");
                fp=fopen("users.txt","rb+");
                cout << "\nDelete Another Record(Y/N): ";
                fflush(stdin);
                another=getchar();
            }
            break;
        case '5':
            fclose(fp);
            cout << "\nTHANK YOU\n";
            exit(0);
        }

    }
system("pause");
return 0;
}
