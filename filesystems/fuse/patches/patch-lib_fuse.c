$NetBSD: patch-lib_fuse.c,v 1.1 2023/09/08 06:01:04 vins Exp $

Don't discard const qualifier from type.

--- lib/fuse.c.orig	2019-01-04 13:38:34.000000000 +0000
+++ lib/fuse.c
@@ -1619,7 +1619,7 @@ static int fuse_compat_statfs(struct fus
 
 #else /* __FreeBSD__ || __NetBSD__ */
 
-static inline int fuse_compat_open(struct fuse_fs *fs, char *path,
+static inline int fuse_compat_open(struct fuse_fs *fs, const char *path,
 				   struct fuse_file_info *fi)
 {
 	return fs->op.open(path, fi);
