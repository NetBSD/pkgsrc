$NetBSD: patch-view2.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- view2.c.orig	1995-10-19 15:20:25.000000000 +0000
+++ view2.c
@@ -72,6 +72,8 @@
 #define VINTERVAL    15*1000
 #define PLACEHOLDER  "<>"
 
+static void delete_viewer_dir(int pid);
+
 struct view_dialog {
 	struct view_dialog *next;
 	Widget w_dialog;
@@ -462,8 +464,7 @@ XtPointer call_data;
  *                     exist, or if unable to delete the directory or its
  *                     contents.
  */
-delete_viewer_dir(pid)
-int pid;
+static void delete_viewer_dir(int pid)
 {
 	char *dir = NULL;
 	struct viewdir_link *ptr;
@@ -906,8 +907,7 @@ char *file;
  * mark_viewdir_for_removal - Flag the directory used by the external
  *                            viewer with "pid" as no longer needed.
  */
-mark_viewdir_for_removal(pid)
-int pid;
+void mark_viewdir_for_removal(int pid)
 {
 	struct viewdir_link *ptr = viewdir_head;
 
