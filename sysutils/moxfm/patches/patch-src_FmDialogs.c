$NetBSD: patch-src_FmDialogs.c,v 1.1 2025/04/11 01:49:11 nia Exp $

Convert errno to a string in a more standard way.

--- src/FmDialogs.c.orig	2025-04-11 00:47:28.898851330 +0000
+++ src/FmDialogs.c
@@ -23,12 +23,6 @@
 
 #define TRASHDIR "/.trash"	/* relative to home dir */
 
-#ifndef linux
-#ifndef __NetBSD__
-extern char *sys_errlist[];
-#endif
-#endif
-
 static char error_string[MAXPATHLEN+256];
 
 typedef enum { Question, Information, Error, Warning } DialogType;
@@ -230,7 +224,7 @@ void unmountDialog(UnmountProcRec *data)
 
 void copyError(String from, String to)
 {
- sprintf(error_string, "Error copying %s\nto %s:\n%s", from, to, sys_errlist[errno]);
+ sprintf(error_string, "Error copying %s\nto %s:\n%s", from, to, strerror(errno));
  askQuestion(getAnyShell(), error_string, False, False, False, Error, None, copyErrorProc, NULL);
 }
 
@@ -333,7 +327,7 @@ int opError(Widget shell, String msg, St
 {
  int answ = -1;
 
- sprintf(error_string, "%s\n%s:\n%s", msg, fname, sys_errlist[errno]);
+ sprintf(error_string, "%s\n%s:\n%s", msg, fname, strerror(errno));
  askQuestion(shell, error_string, False, False, False, Error, None, operr_callback, &answ);
  while (answ == -1)
      XtAppProcessEvent(app_context, XtIMAll);
@@ -734,5 +728,5 @@ void error(Widget shell, String line1, S
 
 void sysError(Widget shell, String line)
 {
- error(shell, line, sys_errlist[errno]);
+ error(shell, line, strerror(errno));
 }
