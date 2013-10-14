$NetBSD: patch-main.c,v 1.1 2013/10/14 13:33:31 roy Exp $

--- main.c.orig	2000-01-26 00:11:56.000000000 +0000
+++ main.c
@@ -115,8 +115,6 @@ void make_menus(int num_menus, char **me
 
     menus_active = FALSE;
     /*initialize screen routines*/
-    sLang_init();
-    set_color_schemes();
     ncurses_init();
     set_ncurses_color_schemes();
     create_windows();
@@ -125,19 +123,9 @@ void make_menus(int num_menus, char **me
     change_channel(&ch1,mp3Path1);
     change_channel(&ch2,mp3Path2);
 
-
     /*display windows*/
-    display_bar(num_menus, menu_name);
-    display_ch_window(active_channel);
-    display_track_path(active_channel,sim_play,ch1_current,ch2_current);
-    display_track_status();
-    adjust_display(get_code());
-    display_listdata();
-    display_player_status(sim_play,playmode);
-    display_volume(ch1_volume_pos,ch2_volume_pos,active_bar);
-    display_speed(ch1_speed_pos,ch2_speed_pos,active_bar);
-    display_fader(fader_pos);
-    
+    refresh_windows();
+    display_bar(num_menus,menu_name);
 
     while(TRUE)
     {
@@ -149,9 +137,9 @@ void make_menus(int num_menus, char **me
        if((ch1.end==1)||(ch2.end==1)) display_track_status();
        if(rcount==5)
        {
-           refresh_windows();
-           display_bar(num_menus, menu_name);
-           rcount=0;
+            refresh_windows();
+	    display_bar(num_menus,menu_name);
+            rcount=0;
        }
 
        if(playmode==1) /*loop play*/
@@ -173,7 +161,7 @@ void make_menus(int num_menus, char **me
            }
            
        }
-       else if(playmode==2)  /*continous play*/
+       else if(playmode==2)  /*continous play*/
        {
            if((ch1.on==0)&&(ch1.end==1))
            {
@@ -215,7 +203,7 @@ void make_menus(int num_menus, char **me
            }
            
        }
-       else if(playmode==3)  /*random play*/
+       else if(playmode==3)  /*random play*/
        {
            if((ch1.on==0)&&(ch1.end==1))
            {
@@ -259,9 +247,9 @@ void make_menus(int num_menus, char **me
         {
             {
                 display_info(inactive_info);
-                switch(get_code())
+                switch(getch())
                 {
-                case SL_KEY_LEFT:
+                case KEY_LEFT:
                     vpos=0;
                     hpos=(hpos>0) ? --hpos: num_menus-1;
                     display_bar(num_menus, menu_name);
@@ -270,7 +258,7 @@ void make_menus(int num_menus, char **me
                     display_menu(menu_item,num_items);
                     break;
 
-                case SL_KEY_RIGHT:
+                case KEY_RIGHT:
                     vpos=0;
                     hpos=(hpos<num_menus-1) ? ++hpos: 0;
                     display_bar(num_menus, menu_name);
@@ -279,28 +267,27 @@ void make_menus(int num_menus, char **me
                     display_menu(menu_item,num_items);
                     break;
 
-                case SL_KEY_UP:
+                case KEY_UP:
                     vpos=(vpos>0) ? --vpos: num_items[hpos]-1;
                     display_menu(menu_item,num_items);
                     break;
 
-                case SL_KEY_DOWN:
+                case KEY_DOWN:
                     vpos=(vpos<num_items[hpos]-1) ? ++vpos:0;
                     display_menu(menu_item,num_items);
                     break;
 
-                case 10:
-                case ENTER:
+		case '\n':
+                case KEY_ENTER:
                     menus_active=FALSE;
                     menu_action(menu_item[hpos][vpos]);
                     vpos=0;
                     display_ch_window(active_channel);
                     display_listdata();
+                    display_bar(num_menus,menu_name);
                     break;
 
-                
-                /*case KEY_F(1):*/
-                case '`':
+                case KEY_F(1):
                     vpos=0;
                     menus_active=FALSE;
                     display_ch_window(active_channel);
@@ -318,42 +305,41 @@ void make_menus(int num_menus, char **me
     	else
         {
             display_info(inactive_info);
-            extcode = get_code();
+            extcode = getch();
 
             switch(extcode)
             {
-            case 10:
-            case ENTER: /*enter key pressed, selects track in active channel */
+	    case '\n':
+            case KEY_ENTER: /*enter key pressed, selects track in active channel */
                 if(active_channel==CHANNEL_1)
                 {
                     ch1_speed=1.0;ch1_speed_pos=0;ch1.speed=ch1_speed;
+                    ch1_last=ch1_current;
                     if(sim_play) /*starts same track in both channels*/
                     {
-                        /* ch2_current = ch1_current;*/
                         ch2_speed=1.0;ch2_speed_pos=0;ch2.speed=ch2_speed;
                         mp3Path2=track_selection(&ch2,ch1_current,mp3Path1);
                         mp3Path1=track_selection(&ch1,ch1_current,mp3Path1);
                         ch2_Head=ch1_Head;
                         ch2_current=ch1_current;
-
+			ch2_last=ch1_last;
                     }
                     else mp3Path1=track_selection(&ch1,ch1_current,mp3Path1);
-                    ch1_last=ch1_current;
                 }
                 else
                 {
                     ch2_speed=1.0;ch2_speed_pos=0; ch2.speed=ch2_speed;
+                    ch2_last=ch2_current;
                     if(sim_play) /*starts same track in both channels*/
                     {
-                        /*ch1_current = ch2_current; */
                         ch1_speed=1.0;ch1_speed_pos=0;ch1.speed=ch1_speed;
                         mp3Path1=track_selection(&ch1,ch2_current,mp3Path2);
                         mp3Path2=track_selection(&ch2,ch2_current,mp3Path2);
-                        ch1_current=ch2_current;
                         ch1_Head=ch2_Head;
+                        ch1_current=ch2_current;
+			ch1_last=ch2_last;
                     }
                     else mp3Path2=track_selection(&ch2,ch2_current,mp3Path2);
-                    ch2_last=ch2_current;
                 }
                display_listdata();
                display_track_path(active_channel,sim_play,ch1_last,ch2_last);
@@ -472,7 +458,7 @@ void make_menus(int num_menus, char **me
                 //printf("------- %i ----------\n",playmode);
                 break;
 
-            case SL_KEY_IC:
+            case KEY_IC:
                 if (active_bar==VOLBAR)
                 {
                     ch1_volume_pos--;
@@ -507,7 +493,7 @@ void make_menus(int num_menus, char **me
       
                 break;
 
-            case SL_KEY_HOME:
+            case KEY_HOME:
 
                 if (active_bar==VOLBAR)
                 {
@@ -542,7 +528,7 @@ void make_menus(int num_menus, char **me
                 }
             break;
 
-            case SL_KEY_DELETE:
+            case KEY_DC:
                 if (active_bar==VOLBAR)
                 {
                     ch2_volume_pos--;
@@ -574,7 +560,7 @@ void make_menus(int num_menus, char **me
                 }
                 break;
 
-            case SL_KEY_END:
+            case KEY_END:
                 if (active_bar==VOLBAR)
                 {
                     ch2_volume_pos++;
@@ -605,7 +591,7 @@ void make_menus(int num_menus, char **me
                 }
                 break;
 
-            case SL_KEY_LEFT : /* left arrow pressed, adjusts fader postion */
+            case KEY_LEFT : /* left arrow pressed, adjusts fader postion */
                 fader_pos-- ;
                 if(fader_pos<=-(fader_bars/2))fader_pos=-(fader_bars/2);
                 if(fader_pos == 0)
@@ -620,7 +606,7 @@ void make_menus(int num_menus, char **me
                 display_fader(fader_pos);
                 break;
 
-            case SL_KEY_RIGHT:
+            case KEY_RIGHT:
                 fader_pos++;
                 if(fader_pos>=(fader_bars/2))fader_pos=(fader_bars/2) ;
                 if(fader_pos == 0)
@@ -660,10 +646,10 @@ void make_menus(int num_menus, char **me
                 display_fader(fader_pos);
                 break;
 
-            case SL_KEY_DOWN:
-            case SL_KEY_UP:
-            case SL_KEY_PPAGE:
-            case SL_KEY_NPAGE:
+            case KEY_DOWN:
+            case KEY_UP:
+            case KEY_PPAGE:
+            case KEY_NPAGE:
                 adjust_display(extcode);
                 display_ch_window(active_channel);
                 display_listdata();
@@ -671,9 +657,10 @@ void make_menus(int num_menus, char **me
 
             case'r':  /*redraws screen*/
             case'R':
+		clearok(stdscr,TRUE);
                 refresh_windows();
-                display_bar(num_menus, menu_name);
-                break ;
+		display_bar(num_menus,menu_name);
+                break;
 
             default:
                 for(j=0; j<num_menus; j++)
@@ -792,7 +779,7 @@ void adjust_display(int key)
          a circular linked list*/
     switch(key)
     {
-     case SL_KEY_DOWN:
+     case KEY_DOWN:
             if((counter >= height-1)&&(current->fLink!=NULL))
                {
                    top=top->fLink; current=current->fLink;
@@ -800,7 +787,7 @@ void adjust_display(int key)
             else  if(current->fLink!=NULL) current=current->fLink;
             break;
 
-    case SL_KEY_UP:
+    case KEY_UP:
             if((top->bLink!=NULL)&&(top==current))
             {
                 top=top->bLink; current=current->bLink;
@@ -809,14 +796,14 @@ void adjust_display(int key)
                 if(current->bLink!=NULL) current=current->bLink ;
             break;
 
-    case SL_KEY_NPAGE: /*pagedown*/
+    case KEY_NPAGE: /*pagedown*/
             while((index < height-1)&&(current->fLink!=NULL))
                {
                    top=top->fLink; current=current->fLink; index++;
                }   
             break;
 
-    case SL_KEY_PPAGE:/*pageup*/
+    case KEY_PPAGE:/*pageup*/
             while((index < height-1)&(top->bLink!=NULL))
                {
                    top=top->bLink; current=current->bLink; index++;
@@ -884,11 +871,9 @@ void display_listdata(void)
         height1,width1;
     node *top, *current, *temp;
 
-    
     if (active_channel==CHANNEL_1)
     {
         top=ch1_Head; current=ch1_current;
-        
     }
     else if(active_channel==CHANNEL_2)
     {
@@ -904,46 +889,53 @@ void display_listdata(void)
     while(temp!=bHead){tracktotal++;temp=temp->fLink;}
     
     /* display  current track number and total tracks */
-    /*wmove(chWin,height1-1,width1-15);*/
     mvwprintw(chWin,height1-1,width1-15,"[%5i][%5i]",tracknum,tracktotal);
 
-    touchwin(chWin);
     wrefresh(chWin);
 
     getmaxyx(subWin,height,width);
-    wbkgd(subWin,COLOR_PAIR(9)|A_BOLD);
     
     while (top!=NULL)
     {
+	char *fnstart;
         fpath=top->filePath;
         playcount=top->playcount;
         /*get songname from path, the songname is assumed to be
          the characters after the last forward slash(/) */
-        songname=strstr(strrchr(fpath,'/'),"/")+1;
+	fnstart = strrchr(fpath,'/');
+	if (fnstart == NULL)
+	    songname=fpath;
+	else
+            songname=strstr(fnstart,"/")+1;
         if(current==top)
+	{
             if(active_channel==CHANNEL_1)
             {
-               wbkgdset(subWin,COLOR_PAIR(7)|A_BOLD);
                wattrset(subWin,COLOR_PAIR(7)|A_BOLD);
+               wbkgdset(subWin,COLOR_PAIR(7)|A_BOLD);
             }
             else if(active_channel==CHANNEL_2)
             {
-               wbkgdset(subWin,COLOR_PAIR(8)|A_BOLD);
                wattrset(subWin,COLOR_PAIR(8)|A_BOLD);
+               wbkgdset(subWin,COLOR_PAIR(8)|A_BOLD);
             }
+	}
+	else
+	{
+            wattrset(subWin,COLOR_PAIR(9));
+            wbkgdset(subWin,COLOR_PAIR(9));
+	}
 
         tempname=strdup(songname);
         /*shorten song so that it fits in channel/display window*/
         mvwaddstr(subWin,index,0,tempname); wclrtoeol(subWin);
         mvwprintw(subWin,index,width-6,"*%5i",playcount);
-
-        touchwin(subWin);
-        wrefresh(subWin);
         
-        wbkgdset(subWin,COLOR_PAIR(9)|A_BOLD);
-        index++; if(index==height)return;
+        index++; if(index==height)break;
         top=top->fLink;
     }
+
+    wrefresh(subWin);
 } /*display_listdata */
 
 void menu_action(char *item_name)
@@ -967,21 +959,10 @@ void enter_action(void)
 void exit_prog(void)
 {
     reset_audio();
-    sLang_exit();
+    ncurses_exit();
     gui_exit();
 }/*exit_prog*/
 
-int get_code(void)
-{
-    int key;
-    /*qiflush(); */
-    /*if(clickcount>=15){flushinp(); clickcount=0;}*/
-    if(SLang_input_pending(-10)) key= /*getch();  */
-        SLkp_getkey(); 
-    else  key=0;
-    /*clickcount++;*/
-    return(key);
-}  /* get_code */
 void refresh_windows(void)
 {
     erase();refresh();
