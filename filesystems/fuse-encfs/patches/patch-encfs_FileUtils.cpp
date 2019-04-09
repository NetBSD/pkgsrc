$NetBSD: patch-encfs_FileUtils.cpp,v 1.1 2019/04/09 16:32:28 maya Exp $

Unclear FUSE API mismatch. fuse_unmount as of FUSE 3.0 seems to take
a single argument, but NetBSD perfuse thinks it's since FUSE 2.2.

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
