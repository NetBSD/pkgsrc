$NetBSD: patch-encfs_main.cpp,v 1.6 2022/01/22 18:32:47 pho Exp $

Work around older FUSE API on NetBSD. Already fixed in HEAD.

--- encfs/main.cpp.orig	2018-04-27 08:52:22.000000000 +0000
+++ encfs/main.cpp
@@ -619,7 +619,9 @@ void *encfs_init(fuse_conn_info *conn) {
   auto *ctx = (EncFS_Context *)fuse_get_context()->private_data;
 
   // set fuse connection options
+#if !defined(__NetBSD__) || FUSE_H_ >= 20211204 /* XXX FUSE API too old */
   conn->async_read = 1u;
+#endif
 
 #ifdef __CYGWIN__
   // WinFsp needs this to partially handle read-only FS
