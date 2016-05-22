$NetBSD: patch-libcaja-private_caja-global-preferences.h,v 1.1 2016/05/22 13:01:45 youri Exp $

Fix build on Darwin.

--- libcaja-private/caja-global-preferences.h.orig	2015-07-16 07:11:15.000000000 +0000
+++ libcaja-private/caja-global-preferences.h
@@ -208,18 +208,18 @@ typedef enum
 void caja_global_preferences_init                      (void);
 char *caja_global_preferences_get_default_folder_viewer_preference_as_iid (void);
 
-GSettings *caja_preferences;
-GSettings *caja_media_preferences;
-GSettings *caja_window_state;
-GSettings *caja_icon_view_preferences;
-GSettings *caja_desktop_preferences;
-GSettings *caja_tree_sidebar_preferences;
-GSettings *caja_compact_view_preferences;
-GSettings *caja_list_view_preferences;
-GSettings *caja_extension_preferences;
+extern GSettings *caja_preferences;
+extern GSettings *caja_media_preferences;
+extern GSettings *caja_window_state;
+extern GSettings *caja_icon_view_preferences;
+extern GSettings *caja_desktop_preferences;
+extern GSettings *caja_tree_sidebar_preferences;
+extern GSettings *caja_compact_view_preferences;
+extern GSettings *caja_list_view_preferences;
+extern GSettings *caja_extension_preferences;
 
-GSettings *mate_background_preferences;
-GSettings *mate_lockdown_preferences;
+extern GSettings *mate_background_preferences;
+extern GSettings *mate_lockdown_preferences;
 
 G_END_DECLS
 
