$NetBSD: patch-shell_cc-panel-loader.c,v 1.1 2020/11/10 18:22:23 nia Exp $

mouse panel requires udev, which is non-portable.

user panel requires kerberos, for which detection is broken.

--- shell/cc-panel-loader.c.orig	2020-10-03 22:47:30.597422600 +0000
+++ shell/cc-panel-loader.c
@@ -42,7 +42,6 @@ extern GType cc_default_apps_panel_get_t
 extern GType cc_display_panel_get_type (void);
 extern GType cc_info_overview_panel_get_type (void);
 extern GType cc_keyboard_panel_get_type (void);
-extern GType cc_mouse_panel_get_type (void);
 #ifdef BUILD_NETWORK
 extern GType cc_network_panel_get_type (void);
 extern GType cc_wifi_panel_get_type (void);
@@ -51,7 +50,6 @@ extern GType cc_notifications_panel_get_
 extern GType cc_goa_panel_get_type (void);
 extern GType cc_power_panel_get_type (void);
 extern GType cc_printers_panel_get_type (void);
-extern GType cc_region_panel_get_type (void);
 extern GType cc_removable_media_panel_get_type (void);
 extern GType cc_search_panel_get_type (void);
 extern GType cc_sharing_panel_get_type (void);
@@ -60,7 +58,6 @@ extern GType cc_sound_panel_get_type (vo
 extern GType cc_bolt_panel_get_type (void);
 #endif /* BUILD_THUNDERBOLT */
 extern GType cc_ua_panel_get_type (void);
-extern GType cc_user_panel_get_type (void);
 #ifdef BUILD_WACOM
 extern GType cc_wacom_panel_get_type (void);
 #endif /* BUILD_WACOM */
@@ -106,7 +103,6 @@ static CcPanelLoaderVtable default_panel
   PANEL_TYPE("location",         cc_location_panel_get_type,             NULL),
   PANEL_TYPE("lock",             cc_lock_panel_get_type,                 NULL),
   PANEL_TYPE("microphone",       cc_microphone_panel_get_type,           NULL),
-  PANEL_TYPE("mouse",            cc_mouse_panel_get_type,                NULL),
 #ifdef BUILD_NETWORK
   PANEL_TYPE("network",          cc_network_panel_get_type,              NULL),
   PANEL_TYPE("wifi",             cc_wifi_panel_get_type,                 cc_wifi_panel_static_init_func),
@@ -115,7 +111,6 @@ static CcPanelLoaderVtable default_panel
   PANEL_TYPE("online-accounts",  cc_goa_panel_get_type,                  NULL),
   PANEL_TYPE("power",            cc_power_panel_get_type,                NULL),
   PANEL_TYPE("printers",         cc_printers_panel_get_type,             NULL),
-  PANEL_TYPE("region",           cc_region_panel_get_type,               NULL),
   PANEL_TYPE("removable-media",  cc_removable_media_panel_get_type,      NULL),
   PANEL_TYPE("search",           cc_search_panel_get_type,               NULL),
   PANEL_TYPE("sharing",          cc_sharing_panel_get_type,              NULL),
@@ -125,7 +120,6 @@ static CcPanelLoaderVtable default_panel
 #endif
   PANEL_TYPE("universal-access", cc_ua_panel_get_type,                   NULL),
   PANEL_TYPE("usage",            cc_usage_panel_get_type,                NULL),
-  PANEL_TYPE("user-accounts",    cc_user_panel_get_type,                 NULL),
 #ifdef BUILD_WACOM
   PANEL_TYPE("wacom",            cc_wacom_panel_get_type,                cc_wacom_panel_static_init_func),
 #endif
