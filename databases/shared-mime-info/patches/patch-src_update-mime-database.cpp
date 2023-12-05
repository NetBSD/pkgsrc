$NetBSD: patch-src_update-mime-database.cpp,v 1.1 2023/12/05 20:15:23 markd Exp $

Adapt paths for pkgsrc.

--- src/update-mime-database.cpp.orig	2023-11-12 08:52:33.000000000 +0000
+++ src/update-mime-database.cpp
@@ -2159,7 +2159,7 @@ static void check_in_path_xdg_data(const
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/" PATH_SEPARATOR "/usr/share/";
+		env = PREFIX "/share/" PATH_SEPARATOR "/usr/local/share/" PATH_SEPARATOR "/usr/share/";
 	dirs = g_strsplit(env, PATH_SEPARATOR, 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
