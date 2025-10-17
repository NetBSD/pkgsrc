$NetBSD: patch-src_iopause.c,v 1.1 2025/10/17 13:32:50 jperkin Exp $

Use correct poll argument type.

--- src/iopause.c.orig	2025-10-17 13:27:26.699060341 +0000
+++ src/iopause.c
@@ -33,7 +33,7 @@ int iopause(iopause_fd *x,unsigned int l
     x[i].revents = 0;
 
 #ifdef IOPAUSE_POLL
-  r = poll(x,len,millisecs);
+  r = poll((struct pollfd *)x,len,millisecs);
 
   /* XXX: some kernels apparently need x[0] even if len is 0 */
   /* XXX: how to handle EAGAIN? are kernels really this dumb? */
