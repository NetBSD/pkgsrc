$NetBSD: patch-fuse_rvaultfs.c,v 1.2 2025/02/11 09:14:01 wiz Exp $

Limit __NetBSD__ workaround to versions before NetBSD 10.
https://github.com/rmind/rvault/pull/66

--- fuse/rvaultfs.c.orig	2025-02-11 09:11:35.416381709 +0000
+++ fuse/rvaultfs.c
@@ -19,6 +19,9 @@
 #include <dirent.h>
 #include <errno.h>
 #include <err.h>
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
 
 #define	FUSE_USE_VERSION	26
 #include <fuse.h>
@@ -499,7 +502,7 @@ rvaultfs_run(rvault_t *vault, const char
 	if (debug) {
 		fuse_opt_add_arg(&args, "-odebug");
 	}
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 1000000000)
 	fuse = fuse_new(&args, &rvaultfs_ops, sizeof(rvaultfs_ops), vault);
 	if (fuse == NULL) {
 		return -1;
