$NetBSD: patch-libpkgconf_pkg.c,v 1.3 2025/09/13 22:25:00 wiz Exp $

Fix build on SCO/Xinuos UnixWare 7.
https://github.com/pkgconf/pkgconf/commit/de3ffe21cfa4026175f5b7212473ce10e2d59485

--- libpkgconf/pkg.c.orig	2025-03-06 00:47:55.000000000 +0000
+++ libpkgconf/pkg.c
@@ -80,6 +80,8 @@ pkg_get_parent_dir(pkgconf_pkg_t *pkg)
 	struct stat path_stat;
 	while (!lstat(buf, &path_stat) && S_ISLNK(path_stat.st_mode))
 	{
+		char sourcebuf[PKGCONF_ITEM_SIZE];
+
 		/*
 		 * Have to split the path into the dir + file components,
 		 * in order to extract the directory file descriptor.
@@ -98,13 +100,16 @@ pkg_get_parent_dir(pkgconf_pkg_t *pkg)
 		pkgconf_strlcpy(dirnamebuf, buf, sizeof(dirnamebuf));
 		const char* targetdir = dirname(dirnamebuf);
 
+#ifdef HAVE_DECL_READLINKAT
 		const int dirfd = open(targetdir, O_DIRECTORY);
 		if (dirfd == -1)
 			break;
 
-		char sourcebuf[PKGCONF_ITEM_SIZE];
 		ssize_t len = readlinkat(dirfd, targetfilename, sourcebuf, sizeof(sourcebuf) - 1);
 		close(dirfd);
+#else
+		ssize_t len = readlink(buf, sourcebuf, sizeof(sourcebuf) - 1);
+#endif
 
 		if (len == -1)
 			break;
