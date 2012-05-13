$NetBSD: patch-src_fs.c,v 1.1.1.1 2012/05/13 08:42:20 imil Exp $

Check for sys/statvfs.h.

--- src/fs.c.orig	2012-05-03 21:08:27.000000000 +0000
+++ src/fs.c
@@ -44,6 +44,11 @@
 #include <sys/statfs.h>
 #endif
 
+/* NetBSD, Solaris */
+#ifdef HAVE_SYS_STATVFS_H
+#include <sys/statvfs.h>
+#endif
+
 /* freebsd && netbsd */
 #ifdef HAVE_SYS_PARAM_H
 #include <sys/param.h>
@@ -52,7 +57,7 @@
 #include <sys/mount.h>
 #endif
 
-#if !defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) && !defined (__OpenBSD__) && !defined(__FreeBSD__)
+#if !defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) && !defined (__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <mntent.h>
 #endif
 
@@ -118,6 +123,7 @@ struct fs_stat *prepare_fs_stat(const ch
 
 static void update_fs_stat(struct fs_stat *fs)
 {
+#ifdef HAVE_SYS_STATFS_H
 	struct statfs64 s;
 
 	if (statfs64(fs->path, &s) == 0) {
@@ -125,6 +131,14 @@ static void update_fs_stat(struct fs_sta
 		/* bfree (root) or bavail (non-roots) ? */
 		fs->avail = (long long)s.f_bavail * s.f_bsize;
 		fs->free = (long long)s.f_bfree * s.f_bsize;
+#else
+	struct statvfs s;
+
+	if (statvfs(fs->path, &s) == 0) {
+		fs->free = (long long)s.f_bfree * s.f_frsize;
+		fs->size = (long long)s.f_blocks * s.f_frsize;
+		fs->avail = (long long)s.f_bavail * s.f_frsize;
+#endif
 		get_fs_type(fs->path, fs->type);
 	} else {
 		NORM_ERR("statfs64 '%s': %s", fs->path, strerror(errno));
@@ -138,10 +152,17 @@ static void update_fs_stat(struct fs_sta
 void get_fs_type(const char *path, char *result)
 {
 
-#if defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) || defined(__FreeBSD__) || defined (__OpenBSD__)
+#if defined(HAVE_STRUCT_STATFS_F_FSTYPENAME) || defined(__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__)
 
+#ifdef HAVE_SYS_STATFS_H
 	struct statfs s;
+
 	if (statfs(path, &s) == 0) {
+#else
+	struct statvfs s;
+
+	if (statvfs(path, &s) == 0) {
+#endif
 		strncpy(result, s.f_fstypename, DEFAULT_TEXT_BUFFER_SIZE);
 	} else {
 		NORM_ERR("statfs '%s': %s", path, strerror(errno));
