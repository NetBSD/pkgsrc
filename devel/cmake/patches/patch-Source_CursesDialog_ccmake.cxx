$NetBSD: patch-Source_CursesDialog_ccmake.cxx,v 1.1 2015/12/11 19:23:22 joerg Exp $

--- Source/CursesDialog/ccmake.cxx.orig	2015-12-02 15:43:21.000000000 +0000
+++ Source/CursesDialog/ccmake.cxx
@@ -68,7 +68,11 @@ void onsig(int)
   if (cmCursesForm::CurrentForm)
     {
     endwin();
-    initscr(); /* Initialization */
+    if (initscr() == NULL) {
+      static const char errmsg[] = "terminal setup failed\n";
+      write(STDERR_FILENO, errmsg, sizeof(errmsg) - 1);
+      exit (1);
+    }
     noecho(); /* Echo off */
     cbreak(); /* nl- or cr not needed */
     keypad(stdscr,TRUE); /* Use key symbols as
@@ -154,7 +158,10 @@ int main(int argc, char const* const* ar
     cmCursesForm::DebugStart();
     }
 
-  initscr(); /* Initialization */
+  if (initscr() == NULL) {
+    fprintf(stderr, "terminal setup failed\n");
+    exit (1);
+  }
   noecho(); /* Echo off */
   cbreak(); /* nl- or cr not needed */
   keypad(stdscr,TRUE); /* Use key symbols as
