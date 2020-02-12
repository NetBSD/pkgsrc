$NetBSD: patch-mono_metadata_mono-config.c,v 1.4 2020/02/12 15:25:16 ryoon Exp $

Look for our dllmap in /usr/pkg/etc/mono/config
as opposed to /usr/pkg/etc/mono/mono/config

--- mono/metadata/mono-config.c.orig	2020-02-04 17:00:34.000000000 +0000
+++ mono/metadata/mono-config.c
@@ -676,7 +676,7 @@ mono_config_parse (const char *filename)
 
 	const char *cfg_dir = mono_get_config_dir ();
 	if (cfg_dir) {
-		char *mono_cfg = g_build_filename (cfg_dir, "mono", "config", (const char*)NULL);
+		char *mono_cfg = g_build_filename (cfg_dir, "config", (const char*)NULL);
 		mono_config_parse_file (mono_cfg);
 		g_free (mono_cfg);
 	}
