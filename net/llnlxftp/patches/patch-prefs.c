$NetBSD: patch-prefs.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- prefs.c.orig	1995-10-19 15:20:24.000000000 +0000
+++ prefs.c
@@ -76,6 +76,8 @@
 #define TEXT   1
 #define NUMBER 2
 
+void create_prefs_dialog(void);
+
 char *anonymous_ftp_password;
 char *initial_logfile_name;
 int sort_long_lists_by_date;
@@ -444,7 +446,7 @@ XtPointer call_data;
 /*
  * create_prefs_dialog - Create User Preferences dialog.
  */
-create_prefs_dialog()
+void create_prefs_dialog(void)
 {
 	static int initialized = False;
 	int i;
