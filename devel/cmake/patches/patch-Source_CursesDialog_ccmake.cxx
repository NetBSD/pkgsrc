$NetBSD: patch-Source_CursesDialog_ccmake.cxx,v 1.3 2017/04/11 20:18:54 adam Exp $

initscr() error path

--- Source/CursesDialog/ccmake.cxx.orig	2017-04-10 15:23:06.000000000 +0000
+++ Source/CursesDialog/ccmake.cxx
@@ -49,7 +49,11 @@ void onsig(int /*unused*/)
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
@@ -124,7 +128,10 @@ int main(int argc, char const* const* ar
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
