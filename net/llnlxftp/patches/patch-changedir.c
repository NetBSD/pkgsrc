$NetBSD: patch-changedir.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- changedir.c.orig	2013-03-01 13:52:15.000000000 +0000
+++ changedir.c
@@ -57,6 +57,9 @@
 #include "xftp.h"
 #include "list.h"
 
+void change_directory(int host, char *new_wd);
+void create_changedir_dialog(void);
+
 static Widget w_changeDirDialog;
 
 static char *help_change_dir[] = {
@@ -127,7 +130,7 @@ XtPointer call_data;
 /*
  * create_changedir_dialog - Create "Change Directory" dialog.
  */
-create_changedir_dialog()
+void create_changedir_dialog(void)
 {
 	static int initialized = False;
 	Arg args[1];
@@ -242,9 +245,7 @@ XtPointer call_data;
  *                    routine takes care of report errors, updating the
  *                    display, and updating hinfo[host].wd.
  */
-change_directory(host, new_wd)
-int host;
-char *new_wd;
+void change_directory(int host, char *new_wd)
 {
     char *wd;
 
