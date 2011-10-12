$NetBSD: patch-src_modules_rtp_module-rtp-recv.c,v 1.1 2011/10/12 20:12:35 hans Exp $

--- src/modules/rtp/module-rtp-recv.c.orig	Mon Nov 23 04:57:06 2009
+++ src/modules/rtp/module-rtp-recv.c	Tue Oct 11 19:21:12 2011
@@ -397,11 +397,13 @@
 
     pa_make_udp_socket_low_delay(fd);
 
+#ifdef SO_TIMESTAMP
     one = 1;
     if (setsockopt(fd, SOL_SOCKET, SO_TIMESTAMP, &one, sizeof(one)) < 0) {
         pa_log("SO_TIMESTAMP failed: %s", pa_cstrerror(errno));
         goto fail;
     }
+#endif
 
     one = 1;
     if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0) {
