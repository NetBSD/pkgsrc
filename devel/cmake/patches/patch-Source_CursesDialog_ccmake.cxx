$NetBSD: patch-Source_CursesDialog_ccmake.cxx,v 1.6 2019/11/27 22:32:27 adam Exp $

initscr() error path
include cstdlib for exit

--- Source/CursesDialog/ccmake.cxx.orig	2019-11-26 14:18:07.000000000 +0000
+++ Source/CursesDialog/ccmake.cxx
@@ -2,6 +2,7 @@
    file Copyright.txt or https://cmake.org/licensing for details.  */
 
 #include <csignal>
+#include <cstdlib>
 #include <cstring>
 #include <iostream>
 #include <string>
@@ -52,7 +53,11 @@ void onsig(int /*unused*/)
 {
   if (cmCursesForm::CurrentForm) {
     endwin();
-    initscr();            /* Initialization */
+    if (initscr() == NULL) {
+      static const char errmsg[] = "terminal setup failed\n";
+      write(STDERR_FILENO, errmsg, sizeof(errmsg) - 1);
+      exit (1);
+    }
     noecho();             /* Echo off */
     cbreak();             /* nl- or cr not needed */
     keypad(stdscr, true); /* Use key symbols as KEY_DOWN */
@@ -122,7 +127,10 @@ int main(int argc, char const* const* ar
     cmCursesForm::DebugStart();
   }
 
-  initscr();            /* Initialization */
+  if (initscr() == NULL) {
+    fprintf(stderr, "terminal setup failed\n");
+    exit (1);
+  }
   noecho();             /* Echo off */
   cbreak();             /* nl- or cr not needed */
   keypad(stdscr, true); /* Use key symbols as KEY_DOWN */
