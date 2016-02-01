$NetBSD: patch-unionfs.c,v 1.1 2016/02/01 02:41:21 jmmv Exp $

--- src/unionfs.c.orig	2015-01-14 10:08:20.000000000 +0000
+++ src/unionfs.c
@@ -23,8 +23,10 @@
 
 #if __APPLE__
 #include <fuse_common.h>
-#else
+#elif defined linux
 #include <fuse/fuse_common.h>
+#else
+#include <fuse.h>
 #endif
 
 #include <stdio.h>
@@ -267,6 +269,7 @@ static int unionfs_link(const char *from
 	RETURN(0);
 }
 
+#if defined(FUSE_IOCTL_COMPAT)
 static int unionfs_ioctl(const char *path, int cmd, void *arg, struct fuse_file_info *fi, unsigned int flags, void *data) {
 	(void) path;
 	(void) arg; // avoid compiler warning
@@ -303,6 +306,7 @@ static int unionfs_ioctl(const char *pat
 
 	return 0;
 }
+#endif
 
 /**
  * unionfs mkdir() implementation
@@ -806,7 +810,9 @@ static struct fuse_operations unionfs_op
 	.fsync = unionfs_fsync,
 	.getattr = unionfs_getattr,
 	.init = unionfs_init,
+#if defined(FUSE_IOCTL_COMPAT)
 	.ioctl = unionfs_ioctl,
+#endif
 	.link = unionfs_link,
 	.mkdir = unionfs_mkdir,
 	.mknod = unionfs_mknod,
