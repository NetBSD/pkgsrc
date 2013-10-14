$NetBSD: patch-nctgui.c,v 1.1 2013/10/14 13:33:31 roy Exp $

--- nctgui.c.orig	2000-01-28 16:30:52.000000000 +0000
+++ nctgui.c
@@ -31,6 +31,10 @@ void ncurses_init(void)
 {
     (void) initscr();
     curs_set(0);
+    cbreak();
+    noecho();
+    timeout(2);
+    keypad(stdscr,TRUE);
 }/* ncurses_init */
 
 void ncurses_exit(void)
@@ -66,24 +70,23 @@ void display_bar(int num_menus,char **me
     int j;
     int maxY,maxX;
 
-    wattrset(barWin,COLOR_PAIR(2)); wbkgdset(barWin,COLOR_PAIR(2));
+    wbkgdset(barWin,COLOR_PAIR(2));
+    wmove(barWin,0,0); wclrtoeol(barWin);
 
-    wmove(barWin,0,0); wclrtoeol(barWin);  wrefresh(barWin);
     for(j=0; j<num_menus; j++)
     {
         wmove(barWin,0,(j*MENU_WIDTH));
         if(j==hpos && menus_active)
-        {
             wattrset(barWin,COLOR_PAIR(3)|A_BOLD);
-        }
-        waddstr(barWin,menu_name[j]); wrefresh (barWin);
+	else
+            wattrset(barWin,COLOR_PAIR(2));
+        waddstr(barWin,menu_name[j]);
 
         wattrset(barWin,COLOR_PAIR(15));
         getmaxyx(stdscr,maxY,maxX); mvwaddstr(barWin,0,maxX-20,emixer_version);
-        
-        wattrset(barWin,COLOR_PAIR(2));
-        wrefresh (barWin);
     }
+
+    wrefresh (barWin);
 } /* display_bar */
 
 /*Display additional info at bottom of screen*/
@@ -106,14 +109,14 @@ void display_menu(char *menu_item[][MAX_
     
     for(j=0;j<num_items[hpos];j++)
     {
-        if(j==vpos){wattrset(subWn,COLOR_PAIR(3)); wbkgdset(subWn,COLOR_PAIR(3)); }
+        if(j==vpos){wattrset(subWn,COLOR_PAIR(3)|A_BOLD);wbkgdset(subWn,COLOR_PAIR(3)); }
         else {wattrset(subWn,COLOR_PAIR(2));wbkgdset(subWn,COLOR_PAIR(2)); }
 
         wmove(subWn,j+1,1);
         waddstr(subWn,menu_item[hpos][j]); wclrtoeol(subWn);
-        wrefresh(subWn);
     }
-    wattrset(subWn,COLOR_PAIR(2));wbkgdset(subWn,COLOR_PAIR(2));
+    wattrset(subWn,COLOR_PAIR(2)|A_ALTCHARSET);
+    wbkgdset(subWn,COLOR_PAIR(2));
     box(subWn,0,0);
     wrefresh(subWn);
 } /* display_menu */
@@ -127,7 +130,8 @@ void display_ch_window(int active_channe
     switch(active_channel)
     {
     case CHANNEL_1:
-        wbkgd(chWin,COLOR_PAIR(11)|A_BOLD);
+	wattrset(chWin,COLOR_PAIR(11)|A_BOLD|A_ALTCHARSET);
+        wbkgdset(chWin,COLOR_PAIR(11)|A_BOLD);
         box(chWin,0,0);
         wmove(chWin,0,2);
         wattrset(chWin,COLOR_PAIR(5)|A_BOLD|A_BLINK);
@@ -137,7 +141,8 @@ void display_ch_window(int active_channe
         break;
      
     case CHANNEL_2:
-        wbkgd(chWin,COLOR_PAIR(12)|A_BOLD);
+	wattrset(chWin,COLOR_PAIR(12)|A_BOLD|A_ALTCHARSET);
+        wbkgdset(chWin,COLOR_PAIR(12)|A_BOLD);
         box(chWin,0,0);
         wmove(chWin,0,width-13);
         wattrset(chWin,COLOR_PAIR(6)|A_BOLD|A_BLINK);
@@ -155,6 +160,7 @@ void display_fader(int fader_pos)
     int centre, j;
 
     centre=(FADER_BARS/2)+2;
+    wattrset(faderWin,COLOR_PAIR(1)|A_BOLD|A_ALTCHARSET);
     wbkgd(faderWin,COLOR_PAIR(1)|A_BOLD);
     box(faderWin,0,0);
     wattrset(faderWin,COLOR_PAIR(9)|A_BOLD);
@@ -201,6 +207,7 @@ void display_volume(int ch1_volume_pos,i
 
     getmaxyx(volumeWin,maxY,maxX);
     centre=(VOLUME_BARS/2)+2;
+    wattrset(volumeWin,COLOR_PAIR(1)|A_BOLD|A_ALTCHARSET);
     wbkgd(volumeWin,COLOR_PAIR(1)|A_BOLD);
     box(volumeWin,0,0);
     if(bar==VOLBAR)mvwaddstr(volumeWin,maxY-1,maxX-9,"[Active]");
@@ -263,6 +270,7 @@ void display_speed(int ch1_speed_pos, in
 
     getmaxyx(speedWin,maxY,maxX);
     centre=(SPEED_BARS/2)+2;
+    wattrset(speedWin,COLOR_PAIR(1)|A_BOLD|A_ALTCHARSET);
     wbkgd(speedWin,COLOR_PAIR(1)|A_BOLD);
     box(speedWin,0,0);
     if(bar==SPDBAR)mvwaddstr(speedWin,maxY-1,maxX-9,"[Active]");
@@ -323,6 +331,7 @@ void display_speed(int ch1_speed_pos, in
 void display_player_status(int sim_play, int playmode)
 {
 
+    wattrset(pStatusWin,COLOR_PAIR(1)|A_BOLD|A_ALTCHARSET);
     wbkgd(pStatusWin,COLOR_PAIR(1)|A_BOLD);
     box(pStatusWin,0,0);
     wattrset(pStatusWin,COLOR_PAIR(9)|A_BOLD);
@@ -343,54 +352,6 @@ void gui_exit(void)
  exit(0);
 } /*gui_exit/*/
 
-void sLang_init(void)
-{
-    SLtt_get_terminfo();
-    SLang_init_tty(0,0,1);
-    SLkp_init();
-    SLsmg_init_smg();
-    SLsig_block_signals();
-    /*ncurses stuff - experimental */
-    (void) initscr();
-    curs_set(0);
-    noecho();
-    keypad(stdscr,TRUE);
-} /* sLang_init*/
-
-
-void sLang_exit(void)
-{
-    /*ncurses stuff - experimental */
-    endwin();
-
-    SLsmg_cls();
-    SLsmg_refresh ();
-    SLsmg_reset_smg();
-    SLang_reset_tty();
-} /* sLang_exit*/
-
-void set_color_schemes(void)
-{
-    SLtt_set_color(1, NULL, "white", "blue");
-    SLtt_set_color(2, NULL, "black", "lightgray");
-    SLtt_set_color(3, NULL, "black", "green");
-    SLtt_set_color(4, NULL, "red","lightgray");
-    SLtt_set_color(5, NULL, "yellow","blue");
-    SLtt_set_color(6, NULL, "lightgray","blue");
-    SLtt_set_color(7, NULL, "yellow","black");
-    SLtt_set_color(8, NULL, "green","blue");
-    SLtt_set_color(9, NULL, "lightgray","black");
-    SLtt_set_color(10, NULL, "red","black");
-    SLtt_set_color(11, NULL, "brightcyan","black");
-    SLtt_set_color(12, NULL, "brightmagenta","black");
-    SLtt_set_color(13, NULL, "black","brightcyan");
-    SLtt_set_color(14, NULL, "black","brightmagenta");
-    SLtt_set_color(15, NULL, "white","brightcyan");
-    SLtt_set_color(16, NULL, "white","brightmagenta");
-
-
-}/*set_color_schemes*/
-
 void create_windows()
 {
     int maxY, maxX, height, width, origY=1, origX=0;
@@ -398,10 +359,7 @@ void create_windows()
     getmaxyx(stdscr,maxY,maxX);
     height = maxY-4; width  = (maxX/10)*7;
     chWin  = newwin(height,width,origY,origX);
-
-    origY=origY++; origX=origX++ ;
-    height = maxY-6;  width = ((maxX/10)*7)-2;
-    subWin  = newwin(height,width,origY,origX);
+    subWin  = subwin(chWin,height-2,width-2,origY+1,origX+1);
     
     origY=maxY-1; origX=0;
     height = 1;  width = maxX-1;
