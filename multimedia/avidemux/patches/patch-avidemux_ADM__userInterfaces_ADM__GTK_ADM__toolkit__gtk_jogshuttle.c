$NetBSD: patch-avidemux_ADM__userInterfaces_ADM__GTK_ADM__toolkit__gtk_jogshuttle.c,v 1.1 2012/07/03 17:38:31 joerg Exp $

--- avidemux/ADM_userInterfaces/ADM_GTK/ADM_toolkit_gtk/jogshuttle.c.orig	2012-07-03 12:04:00.000000000 +0000
+++ avidemux/ADM_userInterfaces/ADM_GTK/ADM_toolkit_gtk/jogshuttle.c
@@ -110,7 +110,7 @@ jog_shuttle_button_release (GtkWidget *w
 	
 	widget = GTK_WIDGET (wheel);
 	
-	if (!widget->window) return;
+	if (!widget->window) return FALSE;
 
 	region = gdk_drawable_get_clip_region (widget->window);
 	gdk_window_invalidate_region (widget->window, region, TRUE);
@@ -144,15 +144,16 @@ jog_shuttle_motion_notify (GtkWidget *wh
 	priv->offset = event->x - priv->start;
 	priv->start = event->x;
 
-	if (!widget->window) return;
+	if (!widget->window) return FALSE;
 	
-	if ((priv->offset+priv->pos[3]) > width || (priv->offset+priv->pos[3]) < 0) return;
+	if ((priv->offset+priv->pos[3]) > width || (priv->offset+priv->pos[3]) < 0) return FALSE;
 	
 	region = gdk_drawable_get_clip_region (widget->window);
 	gdk_window_invalidate_region (widget->window, region, TRUE);
 	gdk_window_process_updates (widget->window, TRUE);
 
 	gdk_region_destroy (region);
+	return TRUE;
 }
 
 static void
