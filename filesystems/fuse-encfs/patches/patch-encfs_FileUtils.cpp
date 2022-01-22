$NetBSD: patch-encfs_FileUtils.cpp,v 1.4 2022/01/22 18:32:47 pho Exp $

NetBSD ReFUSE didn't have the fuse_unmount from FUSE 2.2 - FUSE 2.9.
Workaround by using the version belonging to FUSE >= 3.0.

Already fixed in HEAD.

--- encfs/FileUtils.cpp.orig	2018-04-27 08:52:22.000000000 +0000
+++ encfs/FileUtils.cpp
@@ -1734,7 +1734,11 @@ RootPtr initFS(EncFS_Context *ctx, const
 
 void unmountFS(const char *mountPoint) {
   // fuse_unmount returns void, is assumed to succeed
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+  fuse_unmount(fuse_get_context()->fuse);
+#else
   fuse_unmount(mountPoint, nullptr);
+#endif
 #ifdef __APPLE__
   // fuse_unmount does not work on Mac OS, see #428
   // However it makes encfs to hang, so we must unmount
