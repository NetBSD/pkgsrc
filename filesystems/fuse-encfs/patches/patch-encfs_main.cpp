$NetBSD: patch-encfs_main.cpp,v 1.2 2017/11/11 03:18:16 gdt Exp $

--- encfs/main.cpp.orig	2017-07-25 18:26:45.000000000 +0000
+++ encfs/main.cpp
@@ -488,8 +488,10 @@ static void *idleMonitor(void *);
 void *encfs_init(fuse_conn_info *conn) {
   EncFS_Context *ctx = (EncFS_Context *)fuse_get_context()->private_data;
 
+#ifndef __NetBSD__ /* XXX FUSE API too old */
   // set fuse connection options
   conn->async_read = true;
+#endif
 
   // if an idle timeout is specified, then setup a thread to monitor the
   // filesystem.
