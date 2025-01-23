$NetBSD: patch-fuse_rvaultfs.c,v 1.1 2025/01/23 02:36:52 pho Exp $

Remove __NetBSD__ workaround for old versions of NetBSD librefuse. The
workaround now cause a build failure.

https://github.com/rmind/rvault/pull/66

--- fuse/rvaultfs.c.orig	2025-01-23 02:03:33.171342947 +0000
+++ fuse/rvaultfs.c
@@ -499,22 +499,6 @@ rvaultfs_run(rvault_t *vault, const char
 	if (debug) {
 		fuse_opt_add_arg(&args, "-odebug");
 	}
-#if defined(__NetBSD__)
-	fuse = fuse_new(&args, &rvaultfs_ops, sizeof(rvaultfs_ops), vault);
-	if (fuse == NULL) {
-		return -1;
-	}
-	if (fuse_mount(fuse, mountpoint) == -1) {
-		fuse_destroy(fuse);
-		return -1;
-	}
-	if (!fg) {
-		(void)fuse_daemonize(fuse);
-	}
-	ret = fuse_loop(fuse);
-	app_log(LOG_DEBUG, "%s: exited fuse_loop() with %d", __func__, ret);
-	fuse_unmount(fuse);
-#else
 	struct fuse_chan *chan;
 
 	if ((chan = fuse_mount(mountpoint, &args)) == NULL) {
@@ -529,7 +513,6 @@ rvaultfs_run(rvault_t *vault, const char
 	ret = fuse_loop(fuse);
 	app_log(LOG_DEBUG, "%s: exited fuse_loop() with %d", __func__, ret);
 	fuse_unmount(mountpoint, chan);
-#endif
 	fuse_destroy(fuse);
 	fuse_opt_free_args(&args);
 	return ret;
