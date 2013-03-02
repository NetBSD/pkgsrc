$NetBSD: patch-dirtable.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- dirtable.c.orig	1995-10-19 15:20:21.000000000 +0000
+++ dirtable.c
@@ -71,6 +71,8 @@
 #define UNSELECTED  0
 #define SELECTED    1
 
+void create_dirtable_dialog(int host);
+
 struct table_entry {
 	int state;
 	char *name;
@@ -166,8 +168,7 @@ XtPointer call_data;
  *                          displays the entries of the current working
  *                          directory.
  */
-create_dirtable_dialog(host)
-int host;
+void create_dirtable_dialog(int host)
 {
 	Arg args[1];
 	int i;
