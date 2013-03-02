$NetBSD: patch-dirlong.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- dirlong.c.orig	2013-03-01 13:56:00.000000000 +0000
+++ dirlong.c
@@ -60,6 +60,8 @@
 #include "list.h"
 #include "str.h"
 
+void create_dirlong_dialog(int host);
+
 static int dirlong_dialog_created[] = { False, False };
 
 static struct {
@@ -137,8 +139,7 @@ XtPointer call_data;
  *                         displays a long list of the the entries of the
  *                         current working directory.
  */
-create_dirlong_dialog(host)
-int host;
+void create_dirlong_dialog(int host)
 {
 	int i;
 	Arg args[6];
