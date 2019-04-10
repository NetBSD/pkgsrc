$NetBSD: patch-encfs_main.cpp,v 1.4 2019/04/10 12:33:02 gdt Exp $

Work around older FUSE API on NetBSD.
  
\todo Determine how to qualify this by version.
\todo Enhance API in NetBSD.
\todo File with encfs upstream.

--- encfs/main.cpp.orig	2018-01-28 21:07:41.000000000 +0000
+++ encfs/main.cpp
@@ -530,7 +530,9 @@ void *encfs_init(fuse_conn_info *conn) {
   auto *ctx = (EncFS_Context *)fuse_get_context()->private_data;
 
   // set fuse connection options
+#ifndef __NetBSD__ /* XXX FUSE API too old */
   conn->async_read = 1u;
+#endif
 
   // if an idle timeout is specified, then setup a thread to monitor the
   // filesystem.
