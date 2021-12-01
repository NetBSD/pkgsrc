$NetBSD: patch-encfs_FileUtils.cpp,v 1.3 2021/12/01 04:45:52 pho Exp $

NetBSD ReFUSE doesn't have the fuse_unmount from FUSE 2.2 - FUSE 2.9.
Workaround by using the version belonging to FUSE >= 3.0.

This might be a temporal aberration: NetBSD ReFUSE had the newer FUSE
API before upstream FUSE did.

--- encfs/FileUtils.cpp.orig	2018-04-27 08:52:22.000000000 +0000
+++ encfs/FileUtils.cpp
@@ -1734,7 +1734,11 @@ RootPtr initFS(EncFS_Context *ctx, const
 
 void unmountFS(const char *mountPoint) {
   // fuse_unmount returns void, is assumed to succeed
+#if defined(__NetBSD__)
+  fuse_unmount(fuse_get_context()->fuse);
+#else
   fuse_unmount(mountPoint, nullptr);
+#endif
 #ifdef __APPLE__
   // fuse_unmount does not work on Mac OS, see #428
   // However it makes encfs to hang, so we must unmount
