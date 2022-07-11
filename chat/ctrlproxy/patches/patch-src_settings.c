$NetBSD: patch-src_settings.c,v 1.1 2022/07/11 12:15:17 jperkin Exp $

Provide compat for non-standard __STRING() macro.

--- src/settings.c.orig	2008-12-06 17:36:34.000000000 +0000
+++ src/settings.c
@@ -1009,6 +1009,10 @@ static void config_load_networks(struct
 	g_strfreev(groups);
 }
 
+#ifndef __STRING
+#define __STRING(x) #x
+#endif
+
 #define FETCH_SETTING(data, kf, section, prefix, name) (data)->name = g_key_file_get_string((kf), (section), prefix __STRING(name), NULL)
 #define STORE_SETTING(data, kf, section, prefix, name) g_key_file_set_string((kf), (section), prefix __STRING(name), (data)->name)
 
