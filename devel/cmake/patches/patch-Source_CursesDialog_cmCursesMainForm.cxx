$NetBSD: patch-Source_CursesDialog_cmCursesMainForm.cxx,v 1.1 2015/09/12 15:15:49 joerg Exp $

printw takes a format string.

--- Source/CursesDialog/cmCursesMainForm.cxx.orig	2015-09-07 09:50:58.000000000 +0000
+++ Source/CursesDialog/cmCursesMainForm.cxx
@@ -456,19 +456,19 @@ void cmCursesMainForm::PrintKeys(int pro
     {
     strcpy(fmt, "                           ");
     }
-  printw(fmt);
+  printw("%s", fmt);
   curses_move(y-3,0);
-  printw(firstLine);
+  printw("%s", firstLine);
   curses_move(y-2,0);
-  printw(secondLine);
+  printw("%s", secondLine);
   curses_move(y-1,0);
-  printw(thirdLine);
+  printw("%s", thirdLine);
 
   if (cw)
     {
     sprintf(firstLine, "Page %d of %d", cw->GetPage(), this->NumberOfPages);
     curses_move(0,65-static_cast<unsigned int>(strlen(firstLine))-1);
-    printw(firstLine);
+    printw("%s", firstLine);
     }
 //    }
 
@@ -614,11 +614,10 @@ void cmCursesMainForm::UpdateStatusBar(c
   // Now print both lines
   curses_move(y-5,0);
   attron(A_STANDOUT);
-  char format[] = "%s";
-  printw(format, bar);
+  printw("%s", bar);
   attroff(A_STANDOUT);
   curses_move(y-4,0);
-  printw(version);
+  printw("%s", version);
   pos_form_cursor(this->Form);
 }
 
