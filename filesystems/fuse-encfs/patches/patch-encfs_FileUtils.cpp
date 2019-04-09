$NetBSD: patch-encfs_FileUtils.cpp,v 1.2 2019/04/09 16:43:10 maya Exp $

NetBSD ReFUSE doesn't have the fuse_unmount from FUSE 2.2 - FUSE 2.9.
Workaround by using the version belonging to FUSE >= 3.0.

This might be a temporal aberration: NetBSD ReFUSE had the newer FUSE
API before upstream FUSE did.

--- encfs/FileUtils.cpp.orig	2018-01-28 21:07:41.000000000 +0000
+++ encfs/FileUtils.cpp
@@ -1690,7 +1690,7 @@ bool unmountFS(EncFS_Context *ctx) {
     return false;
   }
 // Time to unmount!
-#if FUSE_USE_VERSION < 30
+#if (FUSE_USE_VERSION < 30) && !defined(__NetBSD__)
   fuse_unmount(ctx->opts->mountPoint.c_str(), nullptr);
 #else
   fuse_unmount(fuse_get_context()->fuse);
