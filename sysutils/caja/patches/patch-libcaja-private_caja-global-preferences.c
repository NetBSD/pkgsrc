$NetBSD: patch-libcaja-private_caja-global-preferences.c,v 1.1 2016/05/22 13:01:45 youri Exp $

Fix build on Darwin.

--- libcaja-private/caja-global-preferences.c.orig	2015-07-16 07:11:15.000000000 +0000
+++ libcaja-private/caja-global-preferences.c
@@ -62,6 +62,17 @@ caja_global_preferences_get_default_fold
     return g_strdup (viewer_iid);
 }
 
+GSettings *caja_preferences;
+GSettings *caja_compact_view_preferences;
+GSettings *caja_desktop_preferences;
+GSettings *caja_extension_preferences;
+GSettings *caja_icon_view_preferences;
+GSettings *caja_list_view_preferences;
+GSettings *caja_media_preferences;
+GSettings *caja_tree_sidebar_preferences;
+GSettings *caja_window_state;
+GSettings *mate_lockdown_preferences;
+
 void
 caja_global_preferences_init (void)
 {
