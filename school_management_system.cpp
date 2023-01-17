#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <regex>
#include <stdio.h>

using namespace std;

class student{
    
    private:
    
    string name , roll_no , father_name , mother_name , contact , address , email , dept , semester , hostel ;
    string teacher_name , teacher_id , teacher_contact , teacher_address , teacher_email , teacher_dept ;
    public : 
        void mainmenu();

        void menu();
        void insert();
        void display();
        void modify();
        void search();
        void deleted();

        void teacher_menu();
        void teacher_insert();
        void teacher_display();
        void teacher_modify();
        void teacher_search();
        void teacher_deleted();


};

void student::mainmenu(){

    mainmenustart:
    int choice;
    char x;
    system("cls");
    //  This function is used to run system/ command prompt commands and here cls is a command to clear the output screen.
    
    cout<<"\t\t\t\t\t********************************"<<endl;
    cout<<"\t\t\t\t\t|| SCHOOL MANAGEMENT SYSTEM ||"<<endl;
    cout<<"\t\t\t\t\t********************************"<<endl;
    
    cout<<"\t\t\t\t\t 1. GO TO STUDENTS RECORDS"<<endl;
    cout<<"\t\t\t\t\t 2. GO TO TEACHERS RECORDS"<<endl;
    cout<<"\t\t\t\t\t 3. EXIT"<<endl;
    
    
    cout<<"\t\t\t\t\t ******************************"<<endl;
    cout<<"\t\t\t\t\t Choose Option (1/2/3)"<<endl;
    cout<<"\t\t\t\t\t ******************************"<<endl;
    cout<<"\t\t\t\t\t Enter your Choice :";
    cin>>choice;
    
    switch(choice){
        case 1 :
            menu();
            break;
        case 2:
            teacher_menu();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"Invalid Choice...Try Again"<<endl;
            break;
    }
    getch();  //it returns ascii value
    goto mainmenustart;
    


}




void student::menu(){
    
    menustart:
    int choice;
    char x;
    system("cls");
    //  This function is used to run system/ command prompt commands and here cls is a command to clear the output screen.
    
    cout<<"\t\t\t\t\t********************************"<<endl;
    cout<<"\t\t\t\t\t|| STUDENT MANAGEMENT SYSTEM ||"<<endl;
    cout<<"\t\t\t\t\t********************************"<<endl;
    
    cout<<"\t\t\t\t\t 1. Enter New Record"<<endl;
    cout<<"\t\t\t\t\t 2. Display Record"<<endl;
    cout<<"\t\t\t\t\t 3. Modify Record"<<endl;
    cout<<"\t\t\t\t\t 4. Search Record"<<endl;
    cout<<"\t\t\t\t\t 5. Delete Record"<<endl;
    cout<<"\t\t\t\t\t 6. Exit"<<endl;
    
    cout<<"\t\t\t\t\t ******************************"<<endl;
    cout<<"\t\t\t\t\t Choose Option (1/2/3/4/5/6)"<<endl;
    cout<<"\t\t\t\t\t ******************************"<<endl;
    cout<<"\t\t\t\t\t Enter your Choice :";
    cin>>choice;
    
    switch(choice){
        case 1 :
        do{
            insert();
            cout<<"\t\t\t\t******************ADD ANOTHER STUDENT RECORD ? (Y/N) *************************"<<endl;
            cin>>x;
        }
        while(x=='y'||x=='Y');
            break;

        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
             deleted();
             break;

        case 6:
            exit(0);
            break;
        default:
            cout<<"Invalid Choice...Try Again"<<endl;
            break;
    }
    getch();  //it returns ascii value
    goto menustart;
    
}

void student::insert(){
    system("cls");
    
    fstream file;
    cout<<"**************************ADD STUDENT DETAILS*************************"<<endl;
    cout<<"\t\t\t\t ENTER NAME:";
    cin>>name;
    cout<<"\t\t\t\t ENTER ROLL NO.:";
    cin>>roll_no;
    cout<<"\t\t\t\t ENTER FATHER NAME:";
    cin>>father_name;
    cout<<"\t\t\t\t ENTER MOTHER NAME:";
    cin>>mother_name;
    cout<<"\t\t\t\t ENTER CONTACT NO.:";
    cin>>contact;
    cout<<"\t\t\t\t ENTER ADDRESS:";
    cin>>address;
    cout<<"\t\t\t\t ENTER EMAIL:";
    cin>>email;
    cout<<"\t\t\t\t ENTER DEPARTMENT:";
    cin>>dept;
    cout<<"\t\t\t\t ENTER SEMESTER:";
    cin>>semester;
    cout<<"\t\t\t\t ENTER HOSTEL NAME:";
    cin>>hostel;
    file.open("studentsrecord.txt", ios::app | ios::out );
    // ios::out --- This means the difference is that ios::ate puts your position to the end of the file when you open it. ios::app instead puts it at the end of the file every time you flush your stream.
    file<<" "<<name<<" "<<roll_no<<" "<<father_name<<" "<<mother_name<<" "<<contact<<" "<<address<<" "<<email<<" "<<dept<<" "<<semester<<" "<<hostel<<"\n";
    file.close();
    
}

void student::display(){
    system("cls");
    fstream file;
    cout<<"********************************************************************STUDENT RECORD TABLE**********************************************************"<<endl;
    file.open("studentsrecord.txt",ios::in);
    int total=1;
    if(!file){
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t No Data is present in the File"<<endl;
        file.close();
    }
    else{
        file>>name>>roll_no>>address>>email>>dept>>semester>>hostel;
        while(!file.eof()){
            cout<<"\t\t\t\t Student No.: "<<total++<<endl;
            cout<<"\t\t\t\t Name :"<<name<<endl;
            cout<<"\t\t\t\t Roll No. : "<<roll_no<<endl;
            cout<<"\t\t\t\t Father Name : "<<father_name<<endl;
            cout<<"\t\t\t\t Mother Name : "<<mother_name<<endl;
            cout<<"\t\t\t\t Contact Number : "<<contact<<endl;
            cout<<"\t\t\t\t Address :"<<address<<endl;
            cout<<"\t\t\t\t Email :"<<email<<endl;
            cout<<"\t\t\t\t Department :"<<dept<<endl;
            cout<<"\t\t\t\t Semester :"<<semester<<endl;
            cout<<"\t\t\t\t Hostel :"<<hostel<<endl;
            cout<<"\n\n";
            file >> name >> roll_no >>father_name>>mother_name>>contact>> address>>email >> dept>> semester>>hostel;
        }
        if(total==0){
            cout<<"\t\t\t\t No Data is present in the File"<<endl;
        }

    }

    file.close();

    
}

void student::modify(){
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n*************************************************************************************************************************************************" << endl;
    cout << "*****************************************************************Student Modify Details**************************************************************" << endl;
    file.open("studentsrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> father_name>> mother_name>>contact>>address>>email >> dept>> semester>>hostel;
        while (!file.eof())
        {
            if (rollno != roll_no)

                file1 << " " << name << " " << roll_no << " " <<father_name<<" " <<mother_name<<" "<<contact<<" "<<address << " " << email<< " " << dept << " " << semester <<" "<<hostel<< "\n";
            else
            {
                cout<<"\t\t\t\t ENTER NAME:";
                cin>>name;
                cout<<"\t\t\t\t ENTER ROLL NO.:";
                cin>>roll_no;
                cout<<"\t\t\t\t ENTER FATHER NAME:";
                cin>>father_name;
                cout<<"\t\t\t\t ENTER MOTHER NAME:";
                cin>>mother_name;
                cout<<"\t\t\t\t ENTER CONTACT NO.:";
                cin>>contact;
                cout<<"\t\t\t\t ENTER ADDRESS:";
                cin>>address;
                cout<<"\t\t\t\t ENTER EMAIL:";
                cin>>email;
                cout<<"\t\t\t\t ENTER DEPARTMENT:";
                cin>>dept;
                cout<<"\t\t\t\t ENTER SEMESTER:";
                cin>>semester;
                cout<<"\t\t\t\t ENTER HOSTEL NAME:";
                cin>>hostel;

               file1 << " " << name << " " << roll_no << " " <<father_name<<" " <<mother_name<<" "<<contact<<" "<<address << " " << email<< " " << dept << " " << semester <<" "<<hostel<< "\n";
               found++;
            }
            file >> name >> roll_no >> father_name>> mother_name>>contact>>address>>email >> dept>> semester>>hostel;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("studentsrecord.txt");
        rename("record.txt", "studentsrecord.txt");
    }
}

void student::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentsrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n********************************************************************************************************************************************" << endl;
        cout << "****************************************************************Student Search Data***********************************************************" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n*********************************************************************************************************************************************" << endl;
        cout << "**************************************************************Student Search Data***********************************************************" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file >> name >> roll_no >> father_name>> mother_name>>contact>>address>>email >> dept>> semester>>hostel;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
           
            cout<<"\t\t\t\t Name :"<<name<<endl;
            cout<<"\t\t\t\t Roll No. : "<<roll_no<<endl;
            cout<<"\t\t\t\t Father Name : "<<father_name<<endl;
            cout<<"\t\t\t\t Mother Name : "<<mother_name<<endl;
            cout<<"\t\t\t\t Contact : "<<contact<<endl;
            cout<<"\t\t\t\t Address :"<<address<<endl;
            cout<<"\t\t\t\t Email :"<<email<<endl;
            cout<<"\t\t\t\t Department :"<<dept<<endl;
            cout<<"\t\t\t\t Semester :"<<semester<<endl;
            cout<<"\t\t\t\t Hostel :"<<hostel<<endl;
            found++;

            }
           file >> name >> roll_no >> father_name>> mother_name>>contact>>address>>email >> dept>> semester>>hostel;
           
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        file.close();
    }
}

void student::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n************************************************************************************************************************************************" << endl;
    cout << "*************************************************************Delete Student Details****************************************************************" << endl;
    file.open("studentsrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student for which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
       file >> name >> roll_no >> father_name>> mother_name>>contact>>address>>email >> dept>> semester>>hostel;
           
      
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " <<father_name<<" " <<mother_name<<" "<<contact<<" "<<address << " " << email<< " " << dept << " " << semester <<" "<<hostel<< "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Deleted Data";
            }
           file >> name >> roll_no >> father_name>> mother_name>>contact>>address>>email >> dept>> semester>>hostel;
           

        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentsrecord.txt");
        rename("record.txt", "studentsrecord.txt");
    }
}


void student::teacher_menu(){
    
    menustart:
    int choice;
    char x;
    system("cls");
    //  This function is used to run system/ command prompt commands and here cls is a command to clear the output screen.
    
    cout<<"\t\t\t\t\t********************************"<<endl;
    cout<<"\t\t\t\t\t|| TEACHER MANAGEMENT SYSTEM ||"<<endl;
    cout<<"\t\t\t\t\t********************************"<<endl;
    
    cout<<"\t\t\t\t\t 1. Enter New Record"<<endl;
    cout<<"\t\t\t\t\t 2. Display Record"<<endl;
    cout<<"\t\t\t\t\t 3. Modify Record"<<endl;
    cout<<"\t\t\t\t\t 4. Search Record"<<endl;
    cout<<"\t\t\t\t\t 5. Delete Record"<<endl;
    cout<<"\t\t\t\t\t 6. Exit"<<endl;
    
    cout<<"\t\t\t\t\t ******************************"<<endl;
    cout<<"\t\t\t\t\t Choose Option (1/2/3/4/5/6)"<<endl;
    cout<<"\t\t\t\t\t ******************************"<<endl;
    cout<<"\t\t\t\t\t Enter your Choice :";
    cin>>choice;
    
    switch(choice){
        case 1 :
        do{
            teacher_insert();
            cout<<"\t\t\t\t******************ADD ANOTHER TEACHER RECORD ? (Y/N) *************************"<<endl;
            cin>>x;
        }
        while(x=='y'||x=='Y');
            break;

        case 2:
            teacher_display();
            break;
        case 3:
            teacher_modify();
            break;
        case 4:
            teacher_search();
            break;
        case 5:
             teacher_deleted();
             break;

        case 6:
            exit(0);
            break;
        default:
            cout<<"Invalid Choice...Try Again"<<endl;
            break;
    }
    getch();  //it returns ascii value
    goto menustart;
    
}


void student::teacher_insert(){

    system("cls");
    
    fstream file;
    cout<<"**************************ADD TEACHER DETAILS*************************"<<endl;
    cout<<"\t\t\t\t ENTER NAME:";
    cin>>teacher_name;
    cout<<"\t\t\t\t ENTER TEACHER ID:";
    cin>>teacher_id;
    cout<<"\t\t\t\t ENTER CONTACT NO.:";
    cin>>teacher_contact;
    cout<<"\t\t\t\t ENTER ADDRESS:";
    cin>>teacher_address;
    cout<<"\t\t\t\t ENTER EMAIL:";
    cin>>teacher_email;
    cout<<"\t\t\t\t ENTER DEPARTMENT:";
    cin>>teacher_dept;
    
    file.open("teachersrecord.txt", ios::app | ios::out );
    // ios::out --- This means the difference is that ios::ate puts your position to the end of the file when you open it. ios::app instead puts it at the end of the file every time you flush your stream.
    file<<" "<<teacher_name<<" "<<teacher_id<<" "<<teacher_contact<<" "<<teacher_address<<" "<<teacher_email<<" "<<teacher_dept<<"\n";
    file.close();



}

void student::teacher_display(){

    system("cls");
    fstream file;
    cout<<"********************************************************************TEACHER RECORD TABLE**********************************************************"<<endl;
    file.open("teachersrecord.txt",ios::in);
    int total=1;
    if(!file){
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t No Data is present in the File"<<endl;
        file.close();
    }
    else{
          file>>teacher_name>>teacher_id>>teacher_contact>>teacher_address>>teacher_email>>teacher_dept;
           while(!file.eof()){
            
            cout<<"\t\t\t\t Teacher No.: "<<total++<<endl;
            cout<<"\t\t\t\t Name :"<<teacher_name<<endl;
            cout<<"\t\t\t\t Teacher Id : "<<teacher_id<<endl;
            cout<<"\t\t\t\t Contact Number : "<<teacher_contact<<endl;
            cout<<"\t\t\t\t Address :"<<teacher_address<<endl;
            cout<<"\t\t\t\t Email :"<<teacher_email<<endl;
            cout<<"\t\t\t\t Department :"<<teacher_dept<<endl;

            cout<<"\n\n";
            file>>teacher_name>>teacher_id>>teacher_contact>>teacher_address>>teacher_email>>teacher_dept;

        }
        if(total==0){
            cout<<"\t\t\t\t No Data is present in the File"<<endl;
        }

    }

    file.close();


}

void student::teacher_modify(){

    system("cls");
    fstream file, file1;
    string id;
    int found = 0;
    cout << "\n*************************************************************************************************************************************************" << endl;
    cout << "*****************************************************************Teacher Modify Details**************************************************************" << endl;
    file.open("teachersrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter ID of Teacher which you want to Modify: ";
        cin >> id;
        file1.open("record1.txt", ios::app | ios::out);
        file>>teacher_name>>teacher_id>>teacher_contact>>teacher_address>>teacher_email>>teacher_dept;
        while (!file.eof())
        {
            if (id != teacher_id)
                file<<" "<<teacher_name<<" "<<teacher_id<<" "<<teacher_contact<<" "<<teacher_address<<" "<<teacher_email<<" "<<teacher_dept<<"\n";
            else
            {
               cout<<"\t\t\t\t ENTER NAME:";
                cin>>teacher_name;
                cout<<"\t\t\t\t ENTER TEACHER ID:";
                cin>>teacher_id;
                cout<<"\t\t\t\t ENTER CONTACT NO.:";
                cin>>teacher_contact;
                cout<<"\t\t\t\t ENTER ADDRESS:";
                cin>>teacher_address;
                cout<<"\t\t\t\t ENTER EMAIL:";
                cin>>teacher_email;
                cout<<"\t\t\t\t ENTER DEPARTMENT:";
                cin>>teacher_dept;

                file1<<" "<<teacher_name<<" "<<teacher_id<<" "<<teacher_contact<<" "<<teacher_address<<" "<<teacher_email<<" "<<teacher_dept<<"\n";
                found++;
            }
            file>>teacher_name>>teacher_id>>teacher_contact>>teacher_address>>teacher_email>>teacher_dept;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Teacher ID Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("teachersrecord.txt");
        rename("record1.txt", "teachersrecord.txt");
    }


}

void student::teacher_search(){

    system("cls");
    fstream file;
    int found = 0;
    file.open("teachersrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n********************************************************************************************************************************************" << endl;
        cout << "****************************************************************Teacher Search Data***********************************************************" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string id;
        cout << "\n*********************************************************************************************************************************************" << endl;
        cout << "**************************************************************Teacher Search Data***********************************************************" << endl;
        cout << "\n Enter ID of Teacher Which You Want to Search: ";
        cin >> id;
        file>>teacher_name>>teacher_id>>teacher_contact>>teacher_address>>teacher_email>>teacher_dept;
        while (!file.eof())
        {
            if (id == teacher_id)
            {
           
            
            cout<<"\t\t\t\t Name :"<<teacher_name<<endl;
            cout<<"\t\t\t\t Teacher Id : "<<teacher_id<<endl;
            cout<<"\t\t\t\t Contact Number : "<<teacher_contact<<endl;
            cout<<"\t\t\t\t Address :"<<teacher_address<<endl;
            cout<<"\t\t\t\t Email :"<<teacher_email<<endl;
            cout<<"\t\t\t\t Department :"<<teacher_dept<<endl;
            found++;

            }
           file>>teacher_name>>teacher_id>>teacher_contact>>teacher_address>>teacher_email>>teacher_dept;
       
        }
        if (found == 0)
        {
            cout << "\n\t\t\tTeacher id Not Found...";
        }
        file.close();
    }


}

void student::teacher_deleted(){

    system("cls");
    fstream file, file1;
    int found = 0;
    string id;
    cout << "\n************************************************************************************************************************************************" << endl;
    cout << "*************************************************************Delete Teacher Details****************************************************************" << endl;
    file.open("teachersrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter ID of Teacher for which you want Delete Data: ";
        cin >> id;
        file1.open("record1.txt", ios::app | ios::out);
        file>>teacher_name>>teacher_id>>teacher_contact>>teacher_address>>teacher_email>>teacher_dept;
          
      
        while (!file.eof())
        {
            if (id != teacher_id)
            {
                file<<" "<<teacher_name<<" "<<teacher_id<<" "<<teacher_contact<<" "<<teacher_address<<" "<<teacher_email<<" "<<teacher_dept<<"\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Deleted Data";
            }
           file>>teacher_name>>teacher_id>>teacher_contact>>teacher_address>>teacher_email>>teacher_dept;
          
      
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Teacher ID Not Found....";
        }
        file1.close();
        file.close();
        remove("teachersrecord.txt");
        rename("record1.txt", "teachersrecord.txt");
    }


}

int main()
{
    student s;
    s.mainmenu();

    return 0;
}
