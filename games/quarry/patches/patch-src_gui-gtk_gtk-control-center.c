$NetBSD: patch-src_gui-gtk_gtk-control-center.c,v 1.1 2012/11/16 00:50:39 joerg Exp $

--- src/gui-gtk/gtk-control-center.c.orig	2012-11-15 15:15:48.000000000 +0000
+++ src/gui-gtk/gtk-control-center.c
@@ -159,7 +159,7 @@ gtk_control_center_present (void)
 
 
 
-inline void
+void
 gtk_control_center_window_created (GtkWindow *window)
 {
   windows = g_slist_prepend (windows, window);
@@ -188,14 +188,14 @@ gtk_control_center_window_destroyed (con
 }
 
 
-inline void
+void
 gtk_control_center_new_reason_to_live (void)
 {
   num_other_reasons_to_live++;
 }
 
 
-inline void
+void
 gtk_control_center_lost_reason_to_live (void)
 {
   if (--num_other_reasons_to_live == 0 && windows == NULL)
