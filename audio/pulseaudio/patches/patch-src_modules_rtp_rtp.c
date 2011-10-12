$NetBSD: patch-src_modules_rtp_rtp.c,v 1.1 2011/10/12 20:12:35 hans Exp $

--- ./src/modules/rtp/rtp.c.orig	Mon Jun  8 21:21:21 2009
+++ ./src/modules/rtp/rtp.c	Tue Oct 11 19:19:50 2011
@@ -278,6 +278,7 @@
         pa_memchunk_reset(&c->memchunk);
     }
 
+#ifdef SO_TIMESTAMP
     for (cm = CMSG_FIRSTHDR(&m); cm; cm = CMSG_NXTHDR(&m, cm)) {
         if (cm->cmsg_level == SOL_SOCKET && cm->cmsg_type == SO_TIMESTAMP)
             memcpy(tstamp, CMSG_DATA(cm), sizeof(struct timeval));
@@ -289,6 +290,9 @@
         pa_log_warn("Couldn't find SO_TIMESTAMP data in auxiliary recvmsg() data!");
         memset(tstamp, 0, sizeof(tstamp));
     }
+#else
+    memset(tstamp, 0, sizeof(tstamp));
+#endif
 
     return 0;
 
