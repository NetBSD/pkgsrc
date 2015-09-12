$NetBSD: patch-Source_CursesDialog_cmCursesStringWidget.cxx,v 1.2 2015/09/12 16:46:11 wiz Exp $

printw takes a format string.
http://public.kitware.com/Bug/view.php?id=15738

Don't use implemention-details of ncurses to see
if the overloading behavior of REQ_DEL_PREV is active, just undo any
damage it may have done.
http://public.kitware.com/Bug/view.php?id=15739

--- Source/CursesDialog/cmCursesStringWidget.cxx.orig	2015-08-13 14:57:00.000000000 +0000
+++ Source/CursesDialog/cmCursesStringWidget.cxx
@@ -168,17 +168,16 @@ bool cmCursesStringWidget::HandleInput(i
     else if ( key == 127 ||
               key == KEY_BACKSPACE )
       {
-      if ( form->curcol > 0 )
-        {
+        FIELD *cur = current_field(form);
         form_driver(form, REQ_DEL_PREV);
-        }
+        if (current_field(form) != cur)
+          {
+          set_current_field(form, cur);
+          }
       }
     else if ( key == ctrl('d') ||key == KEY_DC )
       {
-      if ( form->curcol >= 0 )
-        {
-        form_driver(form, REQ_DEL_CHAR);
-        }
+      form_driver(form, REQ_DEL_CHAR);
       }
     else
       {
@@ -229,17 +228,16 @@ bool cmCursesStringWidget::PrintKeys()
       }
     firstLine[511] = '\0';
     curses_move(y-4,0);
-    printw(firstLine);
+    printw("%s", firstLine);
     curses_move(y-3,0);
-    printw(firstLine);
+    printw("%s", firstLine);
     curses_move(y-2,0);
-    printw(firstLine);
+    printw("%s", firstLine);
     curses_move(y-1,0);
-    printw(firstLine);
+    printw("%s", firstLine);
 
-    sprintf(firstLine,  "Editing option, press [enter] to leave edit.");
     curses_move(y-3,0);
-    printw(firstLine);
+    printw("Editing option, press [enter] to leave edit.");
     return true;
     }
   else
