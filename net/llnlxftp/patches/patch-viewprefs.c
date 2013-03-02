$NetBSD: patch-viewprefs.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- viewprefs.c.orig	1995-10-19 15:20:25.000000000 +0000
+++ viewprefs.c
@@ -71,6 +71,9 @@
 #define EV_IDENTIFIER  "Extension_Viewer:"
 #define MAXQUESTION    1000
 
+static void did_user_forget(void);
+static void create_viewprefs_dialog(void);
+
 struct sl_struct *viewer_mappings;
 int need_to_save_viewprefs = False;
 
@@ -220,7 +223,7 @@ XtPointer call_data;
  * create_viewprefs_dialog - Create dialog for specifying which viewer 
  *                           should be used with each file type.
  */
-create_viewprefs_dialog()
+static void create_viewprefs_dialog(void)
 {
 	static int initialized = False;
 	Widget widget;
@@ -704,7 +707,7 @@ construct_viewprefs_filename()
  * read_viewprefs_from_file - Initializes current viewer preferences with
  *                            values from .xftpview.
  */
-read_viewprefs_from_file()
+void read_viewprefs_from_file(void)
 {
 	static FILE *fp;
 	char viewprefs_line[MAXVPLINE+1];
@@ -1011,7 +1014,7 @@ XtPointer call_data;
  * did_user_forget - Make sure that user did not intend to press "Add"
  *                   or "Replace" button.
  */
-did_user_forget()
+static void did_user_forget(void)
 {
 	char *extension = get_extension();
 	char question[MAXQUESTION];
