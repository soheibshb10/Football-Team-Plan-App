#include <stdio.h>
#include <stdlib.h>
struct Player{
char Name[10];
int Number;
char Place;
struct Player*next;
};





struct Player*New_Player(char Name[],int Number,char Place); //To make a New Player
struct Player*Creat_team(char Name[],int Number,char Place); //Creat team which contains a Goalkeeper
struct Player*Creat_team(char Name[],int Number,char Place); //Add a New player to the team
int Exchange(struct Player*p1,struct Player*p2,struct Player*team);// exchange a player by another one
int Exclude(struct Player*p,struct Player*team); //Exclude a player
void Display(struct Player*head); //Display a player




//To make a New Player
struct Player*New_Player(char Name[],int Number,char Place){
struct Player*p;
p=(struct Player*)malloc(sizeof(struct Player));
strcpy(p->Name,Name);
p->Number=Number;
p->Place=Place;
return p;
}

//Creat team which contains a Goalkeeper
struct Player*Creat_team(char Name[],int Number,char Place){
struct Player*t;
t=(struct Player*)malloc(sizeof(struct Player));
strcpy(t->Name,Name);
t->Number=Number;
t->Place=Place;
t->next=NULL;
return t;
}

//Add a New player to the team
struct Player*Add_Player(char Name[],int Number,char Place,struct Player*team){
    struct Player*lastNode,*p;
    if(team->next==NULL){

    }

    p=New_Player(Name,Number,Place);

   lastNode=team;


    while(lastNode->next !=NULL){
        lastNode=lastNode->next;

    }
lastNode->next=p;

p->next=NULL;

return team;
}

// exchange a player by another one
int Exchange(struct Player*p1,struct Player*p2,struct Player*team){
int Number=p1->Number;

while(team->Number!=Number){
team=team->next;
}
if(team->Number==Number){
strcpy(team->Name,p2->Name);
team->Number=p2->Number;
team->Place=p2->Place;
}
return p2->Number;
}

//Exclude Player
int Exclude(struct Player*p,struct Player*team){
    int Number=p->Number;
    struct Player*ps=team;
    if(team->Number==Number)//THE FIRST PLAYER==Number
        {
        team=team->next;
        ps->next=NULL;
        free(ps);
        return Number;
        }
    else{
      ps=ps->next;
      while(ps->Number!=Number){
     ps=ps->next;
    team=team->next;
}

      if(ps->Number==Number)
       {

 team->next=ps->next;
 free(ps);
return Number;

    }

    }
}




 void Display(struct Player*head){
printf("--------------------------------------The Team--------------------------------------------------\n");
while(head!=NULL){

    printf("Player Number:%d \n",head->Number);
    printf("Player Name:%s \n",head->Name);
    printf("Player Place:%c  \n",head->Place);
    head=head->next;

    printf("\n");

}


}


int main()
{
    char Name[20];
    char Place,bk,y,answ1;
    int Number,ex,exc;
struct Player*head,*p1,*p2,*po;
int DF=1,ML=1,ATT=1;

one:
Place='G';
printf("Enter the Goalkeper (G):\n");
printf("Enter the player number :");
scanf("%d", &Number);
printf("Enter the player name :");
scanf("%20s",&Name);
head=Creat_team(Name,Number,Place);


// enter a team contains 11 players
for(int i=2 ;i<=11;i++){
if(i>=2&&i<6){     //enter a Deffender
Place='D';
printf("Enter Deffender (D) player number %d  :\n",DF);
printf("Enter the new player number :");
scanf("%d", &Number);
printf("Enter the new player name :");
scanf("%20s",&Name);
head=Add_Player(Name,Number,Place,head);
DF++;
}
else if(i>=6&&i<9){ //enter Middefieldr player
Place='M';
printf("Enter Middefieldr  player %d (M) :\n",ML);

printf("Enter the new player number :");
scanf("%d", &Number);
printf("Enter the new player name :");
scanf("%20s",&Name);
head=Add_Player(Name,Number,Place,head);
ML++;
}
else{ //enter a Striker  player
  Place='A';
printf("Enter Striker  player %d (A) :\n",ATT);
printf("Enter the new player number :");
scanf("%d", &Number);
printf("Enter the new player name :");
scanf("%20s",&Name);
head=Add_Player(Name,Number,Place,head);
ATT++;
}
}


// Change a player by another one
scanf("%c",&answ1);
printf("Do you want to change a player (y/n)?");
scanf("%c",&answ1);
while(answ1=='y'||answ1=='Y'){
printf("Enter the exchanged player :\n");
printf("Enter the  player place (G,D,M,A) :");
scanf("%c", &Place);
scanf("%c", &bk);                     //we use this function with empty caracter to avoid memory problems
printf("Enter the  player number :");
scanf("%d", &Number);
scanf("%c", &bk);                 //we use this function with empty caracter to avoid memory problems

printf("Enter the  player name :");
scanf("%20s",&Name);
scanf("%c", &bk);                 //we use this function with empty caracter to avoid memory problems

p1=New_Player(Name,Number,Place);
printf("Enter the alternative player \n");
printf("Enter the player place (G,D,M,A) :");
scanf("%c", &Place);
scanf("%c", &bk);
printf("Enter the player number :");
scanf("%d", &Number);
scanf("%c", &bk);
printf("Enter the player name :");
scanf("%20s",&Name);
scanf("%c", &bk);
p2=New_Player(Name,Number,Place);
ex=Exchange(p1,p2,head);
printf("Exchange  : %d %s->%d %s\n",p1->Number,p1->Name,ex,p2->Name);

printf("Do you want to change a player  (y/n)?");
scanf("%c",&answ1);
}




scanf("%c",&bk);
printf("is a player get Red card :(y/n)");
scanf("%c",&answ1);
while(answ1=='y'||answ1=='Y'){
printf("Enter the  player place (G,D,M,A) :");
scanf("%c", &Place);
scanf("%c", &bk);
printf("Enter the  player number :");
scanf("%d", &Number);
scanf("%c", &bk);

printf("Enter the  player name :");
scanf("%20s",&Name);
scanf("%c", &bk);
po=New_Player(Name,Number,Place);
exc=Exclude(po,head);
printf("The player number %d was excluded  \n",exc);
printf("is a player get Red card :(y/n)");
scanf("%c",&answ1);
}

scanf("%c",&bk);
printf("Do you want to display the team (y/n):");
scanf("%c",&answ1);
if(answ1=='Y'||answ1=='y')
    Display(head);

scanf("%c",&bk);

printf("Do you want to reply the game: ");
scanf("%c",&answ1);
if(answ1=='Y'||answ1=='y'){
goto one;//to restart the programme
}

    return 0;
}
