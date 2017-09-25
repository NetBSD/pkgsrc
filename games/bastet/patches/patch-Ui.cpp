$NetBSD: patch-Ui.cpp,v 1.1 2017/09/25 22:32:16 joerg Exp $

Use format strings.

--- Ui.cpp.orig	2017-09-25 11:56:25.934814498 +0000
+++ Ui.cpp
@@ -183,7 +183,7 @@ namespace Bastet{
 
     BorderedWindow w(d.y,d.x);
     wattrset((WINDOW *)w,COLOR_PAIR(20));
-    mvwprintw(w,0,0,message.c_str());
+    mvwprintw(w,0,0,"%s", message.c_str());
     w.RedrawBorder();
     wrefresh(w);
     PrepareUiGetch();
@@ -200,7 +200,7 @@ namespace Bastet{
     d.y+=3;
     BorderedWindow w(d.y,d.x);
     wattrset((WINDOW *)w,COLOR_PAIR(20));
-    mvwprintw(w,0,0,message.c_str());
+    mvwprintw(w,0,0,"%s",message.c_str());
     w.RedrawBorder();
     wrefresh(w);
     PrepareUiGetch();
@@ -221,7 +221,7 @@ namespace Bastet{
 
     BorderedWindow w(d.y,d.x);
     wattrset((WINDOW *)w,COLOR_PAIR(20));
-    mvwprintw(w,0,0,message.c_str());
+    mvwprintw(w,0,0,"%s", message.c_str());
     w.RedrawBorder();
     wrefresh(w);
     PrepareUiGetch();
@@ -239,7 +239,7 @@ namespace Bastet{
     BorderedWindow w(d.y,d.x);
     wattrset((WINDOW *)w,COLOR_PAIR(20));
     for(size_t i=0;i<choices.size();++i){
-      mvwprintw(w,i,4,choices[i].c_str());
+      mvwprintw(w,i,4,"%s", choices[i].c_str());
     }
     w.RedrawBorder();
     wrefresh(w);
@@ -290,7 +290,7 @@ namespace Bastet{
       Dot d=BoundingRect(msg );
       BorderedWindow w(d.y,d.x);
       wattrset((WINDOW *)w,COLOR_PAIR(20));
-      mvwprintw(w,0,0,msg.c_str());
+      mvwprintw(w,0,0,"%s", msg.c_str());
       w.RedrawBorder();
       ch=getch();
       switch(ch){
