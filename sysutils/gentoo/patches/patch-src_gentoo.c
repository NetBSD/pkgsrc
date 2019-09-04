$NetBSD: patch-src_gentoo.c,v 1.1 2019/09/04 17:35:45 nia Exp $

Avoid embedding home directory references in the binary.

--- src/gentoo.c.orig	2016-02-07 11:53:06.000000000 +0000
+++ src/gentoo.c
@@ -297,7 +297,12 @@ static void init_paths(CfgInfo *cfg)
 		g_string_append(cfg->path.path[PTID_GTKRC], G_DIR_SEPARATOR_S PACKAGE);
 	}
 	else
-		cfg->path.path[PTID_GTKRC] = g_string_new(PATH_GRC);
+	{
+		char *home = getenv("HOME");
+		if(home == NULL)
+			home = "/";
+		cfg->path.path[PTID_GTKRC] = g_string_new(home);
+	}
 	cfg->path.path[PTID_FSTAB] = g_string_new("/etc/fstab");
 	cfg->path.path[PTID_MTAB]  = g_string_new("/proc/mounts");
 
