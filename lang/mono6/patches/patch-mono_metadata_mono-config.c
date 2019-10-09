$NetBSD: patch-mono_metadata_mono-config.c,v 1.2 2019/10/09 22:46:04 maya Exp $

Look for our dllmap in /usr/pkg/etc/mono/config
as opposed to /usr/pkg/etc/mono/mono/config

--- mono/metadata/mono-config.c.orig	2019-09-19 07:46:07.000000000 +0000
+++ mono/metadata/mono-config.c
@@ -682,7 +682,7 @@ mono_config_parse (const char *filename)
 
 	const char *cfg_dir = mono_get_config_dir ();
 	if (cfg_dir) {
-		mono_cfg = g_build_filename (cfg_dir, "mono", "config", NULL);
+		mono_cfg = g_build_filename (cfg_dir, "config", NULL);
 		mono_config_parse_file (mono_cfg);
 		g_free (mono_cfg);
 	}
