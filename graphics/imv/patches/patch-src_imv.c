$NetBSD: patch-src_imv.c,v 1.1 2021/02/03 10:43:42 nia Exp $

Allow the proper configuration path to be substituted.

--- src/imv.c.orig	2020-12-17 20:30:42.000000000 +0000
+++ src/imv.c
@@ -1370,8 +1370,7 @@ static char *get_config_path(void)
     "$HOME/.config/imv/config",
     "$HOME/.imv_config",
     "$HOME/.imv/config",
-    "/usr/local/etc/imv_config",
-    "/etc/imv_config",
+    "@PKG_SYSCONFDIR@/imv_config",
   };
 
   for (size_t i = 0; i < sizeof(config_paths) / sizeof(char*); ++i) {
