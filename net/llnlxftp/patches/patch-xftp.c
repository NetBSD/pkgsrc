$NetBSD: patch-xftp.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- xftp.c.orig	2013-03-01 13:50:11.000000000 +0000
+++ xftp.c
@@ -71,20 +71,24 @@ int depth;
 Visual *visual;
 Window root_window;
 
+void read_cache_from_file(void);
 void ResizeDirtable();
 void DirtableMouse();
 int cb_create_dialogs();
-int create_rconnect_dialog();
-int create_aconnect_dialog();
-int create_verify_dialog();
-int create_prefs_dialog();
-int create_xfermon_dialog();
-int create_mp_monitor_dialog();
-int create_changedir_dialog();
-int create_dirtable_dialog();
-int create_dirlong_dialog();
+void create_rconnect_dialog(void);
+void create_aconnect_dialog(void);
+void create_verify_dialog(void);
+void create_prefs_dialog(void);
+void create_xfermon_dialog(void);
+void create_mp_monitor_dialog(void);
+void create_changedir_dialog(void);
+void create_dirtable_dialog(int);
+void create_dirlong_dialog(int);
 void cb_quit();
 void reapchild();
+void create_icon(void);
+void mark_viewdir_for_removal(int pid);
+void read_viewprefs_from_file(void);
 
 static XtActionsRec actions[] = {
 	{"ResizeDirtable", ResizeDirtable},
