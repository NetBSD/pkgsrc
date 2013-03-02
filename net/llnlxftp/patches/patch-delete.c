$NetBSD: patch-delete.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- delete.c.orig	1995-10-19 15:20:21.000000000 +0000
+++ delete.c
@@ -59,6 +59,8 @@
 #include "list.h"
 #include "str.h"
 
+static void init_delete(int host, int recursive);
+
 struct del_ctrl_block del_ctrl;
 
 extern struct st_host_info hinfo[];
@@ -108,9 +110,7 @@ XtPointer call_data;
 /*
  * init_delete - Initialize delection(s).
  */
-init_delete(host, recursive)
-int host;
-int recursive;
+static void init_delete(int host, int recursive)
 {
 	XmStringTable selected_items;
 	int nselected_items;
