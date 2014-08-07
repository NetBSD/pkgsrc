$NetBSD: patch-src_modules_rtp_rtp.c,v 1.3 2014/08/07 07:43:48 spz Exp $

fix for CVE-2014-3970 taken from pulseaudio git

--- src/modules/rtp/rtp.c.orig	2014-01-23 18:57:55.000000000 +0000
+++ src/modules/rtp/rtp.c
@@ -182,8 +182,29 @@ int pa_rtp_recv(pa_rtp_context *c, pa_me
         goto fail;
     }
 
-    if (size <= 0)
-        return 0;
+    if (size <= 0) {
+        /* size can be 0 due to any of the following reasons:
+         *
+         * 1. Somebody sent us a perfectly valid zero-length UDP packet.
+         * 2. Somebody sent us a UDP packet with a bad CRC.
+         *
+         * It is unknown whether size can actually be less than zero.
+         *
+         * In the first case, the packet has to be read out, otherwise the
+         * kernel will tell us again and again about it, thus preventing
+         * reception of any further packets. So let's just read it out
+         * now and discard it later, when comparing the number of bytes
+         * received (0) with the number of bytes wanted (1, see below).
+         *
+         * In the second case, recvmsg() will fail, thus allowing us to
+         * return the error.
+         *
+         * Just to avoid passing zero-sized memchunks and NULL pointers to
+         * recvmsg(), let's force allocation of at least one byte by setting
+         * size to 1.
+         */
+        size = 1;
+    }
 
     if (c->memchunk.length < (unsigned) size) {
         size_t l;
