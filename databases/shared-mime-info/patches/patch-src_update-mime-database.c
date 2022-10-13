$NetBSD: patch-src_update-mime-database.c,v 1.1 2022/10/13 11:08:43 wiz Exp $

Adapt paths for pkgsrc.

--- src/update-mime-database.c.orig	2022-03-27 10:19:00.000000000 +0000
+++ src/update-mime-database.c
@@ -2174,7 +2174,7 @@ static void check_in_path_xdg_data(const
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/"PATH_SEPARATOR"/usr/share/";
+		env = PREFIX "/share/"PATH_SEPARATOR"/usr/local/share/"PATH_SEPARATOR"/usr/share/";
 	dirs = g_strsplit(env, PATH_SEPARATOR, 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
