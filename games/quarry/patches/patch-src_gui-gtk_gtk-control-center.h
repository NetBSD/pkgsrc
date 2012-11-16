$NetBSD: patch-src_gui-gtk_gtk-control-center.h,v 1.1 2012/11/16 00:50:39 joerg Exp $

--- src/gui-gtk/gtk-control-center.h.orig	2012-11-15 15:15:33.000000000 +0000
+++ src/gui-gtk/gtk-control-center.h
@@ -31,11 +31,11 @@
 
 void		gtk_control_center_present (void);
 
-inline void	gtk_control_center_window_created (GtkWindow *window);
+void	gtk_control_center_window_created (GtkWindow *window);
 gint		gtk_control_center_window_destroyed (const GtkWindow *window);
 
-inline void	gtk_control_center_new_reason_to_live (void);
-inline void	gtk_control_center_lost_reason_to_live (void);
+void	gtk_control_center_new_reason_to_live (void);
+void	gtk_control_center_lost_reason_to_live (void);
 
 void		gtk_control_center_quit (void);
 
