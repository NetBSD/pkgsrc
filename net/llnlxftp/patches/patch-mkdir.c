$NetBSD: patch-mkdir.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- mkdir.c.orig	1995-10-19 15:20:23.000000000 +0000
+++ mkdir.c
@@ -56,6 +56,8 @@
 #include "xftp.h"
 #include "str.h"
 
+static void create_mkdir_dialog(void);
+
 static Widget w_mkdirDialog;
 
 static char *help_make_dir[] = {
@@ -119,7 +121,7 @@ XtPointer call_data;
 /*
  * create_mkdir_dialog - Create the "Make Directory" dialog.
  */
-create_mkdir_dialog()
+static void create_mkdir_dialog(void)
 {
 	static int initialized = False;
     int i;
