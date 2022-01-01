$NetBSD: patch-editor_src_Main.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Use standard headers.
Silence compiler warnings.
Call gethostname() correctly.
Don't use sprintf.

--- editor/src/Main.c.orig	2001-07-03 11:55:17.000000000 +0000
+++ editor/src/Main.c
@@ -17,8 +17,9 @@
 #include <X11/Xutil.h>
 #include <X11/cursorfont.h>
 
-#include <signal.h>
 #include <sys/types.h>
+#include <unistd.h>
+#include <signal.h>
 
 #ifdef HAVE_SPECIALIST_MALLOC_LIBRARY
 #include <malloc.h>
@@ -153,6 +154,10 @@ int ErrorXIO(Display *d)
 
 /* Handler for Toolkit errors, always fatal */
 
+static
+#if defined(__CLANG__) || defined(__GNUC__)
+__attribute__((__noreturn__))
+#endif
 void ErrorXt(char *msg)
 {
   Begin("ErrorXt");
@@ -283,12 +288,14 @@ void SetTitleBar(char **argv)
   title = (String)XtMalloc(200);
 
 #ifdef NO_GETHOSTNAME
-  sprintf(title, "%s", ApplicationName);
+  snprintf(title, 200, "%s", ApplicationName);
 #else
-  if (gethostname(machine, 99))
-    sprintf(title, "%s", ApplicationName);
-  else
-    sprintf(title, "%s  [%s]", ApplicationName, machine);
+  if (gethostname(machine, sizeof(machine)))
+    snprintf(title, 200, "%s", ApplicationName);
+  else {
+    machine[sizeof(machine) - 1] = '\0'; /* just in case */
+    snprintf(title, 200, "%s  [%s]", ApplicationName, machine);
+  }
 #endif
 
   XtSetArg(arg[0], XtNtitle,    (XtArgVal)title);
