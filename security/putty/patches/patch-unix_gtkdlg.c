$NetBSD: patch-unix_gtkdlg.c,v 1.1 2018/08/01 05:34:18 maya Exp $

gdk_beep deprecated, replace with gdk_display_beep.

--- unix/gtkdlg.c.orig	2017-04-24 13:52:45.000000000 +0000
+++ unix/gtkdlg.c
@@ -1037,7 +1037,7 @@ void dlg_set_focus(union control *ctrl, 
  */
 void dlg_beep(void *dlg)
 {
-    gdk_beep();
+    gdk_display_beep(gdk_display_get_default());
 }
 
 #if !GTK_CHECK_VERSION(3,0,0)
@@ -1491,7 +1491,7 @@ static void draglist_move(struct dlgpara
     if ((index < 0) ||
 	(index == 0 && direction < 0) ||
 	(index == g_list_length(children)-1 && direction > 0)) {
-	gdk_beep();
+	gdk_display_beep(gdk_display_get_default());
 	return;
     }
 
