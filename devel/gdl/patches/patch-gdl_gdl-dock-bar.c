$NetBSD: patch-gdl_gdl-dock-bar.c,v 1.1 2013/10/06 19:59:42 joerg Exp $

--- gdl/gdl-dock-bar.c.orig	2013-09-29 14:01:31.000000000 +0000
+++ gdl/gdl-dock-bar.c
@@ -484,7 +484,7 @@ GdlDockBarStyle gdl_dock_bar_get_style(G
 {
     GdlDockBarStyle style;
 
-    g_return_if_fail (GDL_IS_DOCK_BAR (dockbar));
+    g_return_val_if_fail (GDL_IS_DOCK_BAR (dockbar), GDL_DOCK_BAR_AUTO);
 
     g_object_get(G_OBJECT(dockbar), "dockbar-style", &style, NULL);
 
