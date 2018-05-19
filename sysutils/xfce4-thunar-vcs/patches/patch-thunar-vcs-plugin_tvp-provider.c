$NetBSD: patch-thunar-vcs-plugin_tvp-provider.c,v 1.1 2018/05/19 11:47:11 youri Exp $

Update to reflect new thunarx API.

--- thunar-vcs-plugin/tvp-provider.c.orig	2016-06-29 20:09:32.000000000 +0000
+++ thunar-vcs-plugin/tvp-provider.c
@@ -134,8 +134,8 @@ tvp_provider_class_init (TvpProviderClas
 static void
 tvp_provider_menu_provider_init (ThunarxMenuProviderIface *iface)
 {
-  iface->get_file_actions = tvp_provider_get_file_actions;
-  iface->get_folder_actions = tvp_provider_get_folder_actions;
+  iface->get_file_menu_items = tvp_provider_get_file_actions;
+  iface->get_folder_menu_items = tvp_provider_get_folder_actions;
 }
 
 
