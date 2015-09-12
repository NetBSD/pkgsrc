$NetBSD: patch-Source_CursesDialog_cmCursesLongMessageForm.cxx,v 1.1 2015/09/12 15:15:49 joerg Exp $

printw takes a format string.

--- Source/CursesDialog/cmCursesLongMessageForm.cxx.orig	2015-09-07 09:50:13.000000000 +0000
+++ Source/CursesDialog/cmCursesLongMessageForm.cxx
@@ -82,10 +82,10 @@ void cmCursesLongMessageForm::UpdateStat
 
   curses_move(y-4,0);
   attron(A_STANDOUT);
-  printw(bar);
+  printw("%s", bar);
   attroff(A_STANDOUT);
   curses_move(y-3,0);
-  printw(version);
+  printw("%s", version);
   pos_form_cursor(this->Form);
 }
 
@@ -102,7 +102,7 @@ void cmCursesLongMessageForm::PrintKeys(
   sprintf(firstLine,  "Press [e] to exit help");
 
   curses_move(y-2,0);
-  printw(firstLine);
+  printw("%s", firstLine);
   pos_form_cursor(this->Form);
 
 }
