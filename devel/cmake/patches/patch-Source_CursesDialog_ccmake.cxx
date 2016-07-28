$NetBSD: patch-Source_CursesDialog_ccmake.cxx,v 1.2 2016/07/28 17:44:43 prlw1 Exp $

initscr() error path

--- Source/CursesDialog/ccmake.cxx.orig	2016-07-07 14:47:27.000000000 +0000
+++ Source/CursesDialog/ccmake.cxx
@@ -54,7 +54,11 @@ void onsig(int)
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
     keypad(stdscr, TRUE); /* Use key symbols as
@@ -130,7 +134,10 @@ int main(int argc, char const* const* ar
     cmCursesForm::DebugStart();
   }
 
-  initscr();            /* Initialization */
+  if (initscr() == NULL) {
+    fprintf(stderr, "terminal setup failed\n");
+    exit (1);
+  }
   noecho();             /* Echo off */
   cbreak();             /* nl- or cr not needed */
   keypad(stdscr, TRUE); /* Use key symbols as
