$NetBSD: patch-Source_CursesDialog_ccmake.cxx,v 1.4 2017/04/24 22:48:48 maya Exp $

initscr() error path
include cstdlib for exit

--- Source/CursesDialog/ccmake.cxx.orig	2017-04-10 15:23:06.000000000 +0000
+++ Source/CursesDialog/ccmake.cxx
@@ -11,6 +11,7 @@
 #include "cmake.h"
 
 #include <cmsys/Encoding.hxx>
+#include <cstdlib>
 #include <iostream>
 #include <signal.h>
 #include <string.h>
@@ -49,7 +50,11 @@ void onsig(int /*unused*/)
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
@@ -124,7 +129,10 @@ int main(int argc, char const* const* ar
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
