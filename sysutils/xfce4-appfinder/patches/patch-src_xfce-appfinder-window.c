$NetBSD: patch-src_xfce-appfinder-window.c,v 1.1 2012/03/05 13:32:58 roy Exp $

Should return NULL to silence errors.

--- src/xfce-appfinder-window.c.orig	2012-03-05 13:18:51.000000000 +0000
+++ src/xfce-appfinder-window.c
@@ -926,7 +926,7 @@ _xfce_appfinder_window_reload_menu (Xfce
   gchar     *filename = NULL;
   gint       counter = 0;
 
-  g_return_if_fail (XFCE_IS_APPFINDER_WINDOW (window));
+  g_return_val_if_fail (XFCE_IS_APPFINDER_WINDOW (window), NULL);
 
   DBG ("window->menu_filename = %s", window->menu_filename);
 
