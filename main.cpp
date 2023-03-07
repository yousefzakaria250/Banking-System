#include <iostream>
#include<process.h>
#include<stdlib.h>
using namespace std;
struct account_query
{
    int account_number ;
    char firstName[50] ;
    char lastName[50];
    float total_balance ;
};

class Record
{
private :
    account_query clients[100] ;
    static int c ;
public:
    Record()
    {
        //c = 0 ;
    }
    void add_record() ;
    void show_record() ;
    void search_record(int ) ;
    void update_record() ;
    void delete_record();
    void show_main() ;
};
int::Record::c = 0;
void Record::add_record()
{
    cout << "c = " << c << endl;
    cout <<"Enter Account Number : " ;
    cin >> clients[c].account_number ;
    cout <<"Enter first Name : " ;
    cin >> clients[c].firstName ;
    cout <<"Enter Last Name : " ;
    cin >> clients[c].lastName ;
    cout <<"Enter total balance : " ;
    cin >> clients[c].total_balance ;
     c++ ;
}

void Record::show_record()
{
    int acc ;
    cout <<"Enter an Account Number : " ;
    cin >> acc;
    for( int i = 0 ; i < c ;i++)
    {
        if( acc == clients[i].account_number)
        {
            cout << "Account Number = " << clients[i].account_number << endl;
            cout <<"First Name = " << clients[i].firstName << endl;
            cout <<"Last Name = " << clients[i].lastName << endl;
            cout <<"Amount Balance = " << clients[i].total_balance <<endl;
            return ;
        }
    }
    cout <<"Account Number is False ! . " << endl;
}
void Record::search_record(int accNum)
{
     for( int i = 0 ; i < c ;i++)
    {
        if( accNum == clients[i].account_number)
        {
            cout <<"This Account Number Right and details is : " << endl;
            cout << "Account Number = " << clients[i].account_number << endl;
            cout <<"First Name = " << clients[i].firstName << endl;
            cout <<"Last Name = " << clients[i].lastName << endl;
            cout <<"Amount Balance = " << clients[i].total_balance <<endl;
            return ;
        }
    }

    cout <<"Account Number is False ! . " << endl;
}

void Record::update_record()
{
    int acc ,num ;
    float am_Dep , am_with;
    cout <<"Enter Account Number : " << endl;
    cin >> acc ;
    for( int i = 0 ; i < c ;i++)
    {
        if( acc == clients[i].account_number)
        {
            cout << "Account Number is correct .  " << endl;
            cout <<"Enter (1) for Depoisted or (2) for Withdraw cash : " << endl ;
            cin >> num ;
            if(num == 1)
            {
                cout <<"Enter Amount Of money you are depoiste : " ;
                cin  >> am_Dep ;
                clients[i].total_balance+= am_Dep ;
                return ;
            }
            else if(num == 2 )
            {
                cout <<"Enter number you want withdraw : " ;
                cin >> am_with ;
                if( am_with > clients[i].total_balance)
                {
                    cout <<"You have not a sufficient amount to withdraw . " << endl;
                    return ;
                }
                clients[i].total_balance -=am_with ;
                return ;
            }
            else{
                cout <<"you entered an error number ! " << endl;
                return ;
            }
}

    }
    cout <<"Account Number is False . " << endl;
}

void Record::delete_record()
{
    int acc ;
    int t ;
    cout <<"Enter Account Number you are to delete it : " ;
    cin >> acc ;
    for( int i = 0 ; i < c ;i++)
    {
        if( acc == clients[i].account_number)
           {
               t = i  ;
               //clients[t] = null ;
               for( int j = i+1 ; j < c ; j++ )
               {
                   account_query temp = clients[t] ;
                   clients[t] = clients[j];
                   clients[j] = temp ;
               }
                   // swap( clients[t] , clients[j] ) ;
                cout <<"Element is deleted . " << endl;
               c-=1 ;
               return ;
           }

    }
    cout <<"Account is not Founded . " << endl;
}

void Record::show_main()
{
    int n ;
    cout <<"***Acount Information System*** "<< endl;
    cout <<"1-->" << "For Add Account In System " << endl;
    cout <<"2-->" << " For Show Account In System  " << endl;
    cout <<"3-->" << " For Update Account In System  " << endl;
    cout <<"4-->" << " For Search Account In System  " << endl;
    cout <<"5-->" << " For Delete Account In System  " << endl;
    cout <<"6-->"<<  " Quit The Program" << endl;
    cin >> n ;
    if( n == 1)
        Record::add_record() ;
    else if( n==2 )
        Record::show_record() ;
    else if(n==3)
        Record::update_record() ;
 //   else if( n ==4)
   //     Record::search_record();
    else if( n == 5)
        Record::delete_record() ;
    else if(n == 6)
    {
        cout <<"Thanks For Use :)" << endl;
       exit(0);
    }
    else{
        cout <<"You Enter an error choice . " << endl;
        exit(0);
    }

}

int main()
{

    Record r1 ;
    while(true)
    {
        r1.show_main() ;
    }


    Record account_query[10] ;

   account_query[0].add_record() ;
   account_query[0].show_record();
   // r1[0].add_record();
    //r1[1].add_record() ;
    //r1[2].add_record() ;
 //   r1[0].delete_record() ;
   // r1[0].show_record() ;
    //r1.add_record() ;
    //r2.add_record() ;
    //r3.add_record();
    //r2.delete_record() ;
   // r2.show_record();
  //  r2.add_record();
    //r1.show_record() ;
    //r2.show_record();
   // r1.update_record() ;
 //  r1.delete_record();
   // r1.show_record();

    return 0;
}
