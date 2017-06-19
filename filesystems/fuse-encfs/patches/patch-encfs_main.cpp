$NetBSD: patch-encfs_main.cpp,v 1.1 2017/06/19 18:41:39 maya Exp $

--- encfs/main.cpp.orig	2016-09-18 20:16:04.000000000 +0000
+++ encfs/main.cpp
@@ -488,8 +488,10 @@ static void *idleMonitor(void *);
 void *encfs_init(fuse_conn_info *conn) {
   EncFS_Context *ctx = (EncFS_Context *)fuse_get_context()->private_data;
 
+#ifndef __NetBSD__ /* XXX FUSE API too old */
   // set fuse connection options
   conn->async_read = true;
+#endif
 
   if (ctx->args->isDaemon) {
     // Switch to using syslog.
