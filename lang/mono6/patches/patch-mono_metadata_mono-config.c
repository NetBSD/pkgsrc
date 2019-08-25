$NetBSD: patch-mono_metadata_mono-config.c,v 1.1 2019/08/25 16:37:01 maya Exp $

Look for our dllmap in /usr/pkg/etc/mono/config
as opposed to /usr/pkg/etc/mono/mono/config

--- mono/metadata/mono-config.c.orig	2019-07-18 07:46:08.000000000 +0000
+++ mono/metadata/mono-config.c
@@ -694,7 +694,7 @@ mono_config_parse (const char *filename)
 
 	const char *mono_cfg_dir = mono_get_config_dir ();
 	if (mono_cfg_dir) {
-		mono_cfg = g_build_filename (mono_cfg_dir, "mono", "config", NULL);
+		mono_cfg = g_build_filename (mono_cfg_dir, "config", NULL);
 		mono_config_parse_file (mono_cfg);
 		g_free (mono_cfg);
 	}
