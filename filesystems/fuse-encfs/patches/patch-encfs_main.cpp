$NetBSD: patch-encfs_main.cpp,v 1.5 2021/12/01 04:45:52 pho Exp $

Work around older FUSE API on NetBSD.
  
\todo Determine how to qualify this by version.
\todo Enhance API in NetBSD.
\todo File with encfs upstream.

--- encfs/main.cpp.orig	2018-04-27 08:52:22.000000000 +0000
+++ encfs/main.cpp
@@ -619,7 +619,9 @@ void *encfs_init(fuse_conn_info *conn) {
   auto *ctx = (EncFS_Context *)fuse_get_context()->private_data;
 
   // set fuse connection options
+#ifndef __NetBSD__ /* XXX FUSE API too old */
   conn->async_read = 1u;
+#endif
 
 #ifdef __CYGWIN__
   // WinFsp needs this to partially handle read-only FS
