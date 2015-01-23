$NetBSD: patch-wordaccess_be_aligned.h,v 1.1 2015/01/23 11:26:40 jdc Exp $

--- lib/util/wordaccess_be_aligned.h.dist	2014-09-01 22:22:28.000000000 +0100
+++ lib/util/wordaccess_be_aligned.h	2015-01-23 09:22:52.000000000 +0000
@@ -24,7 +24,7 @@
 static __inline__ void
 wordintToBytes(wordintBytes * const bytesP,
                wordint        const wordInt) {
-    uint16_t const hi = ((wordInt >> 48) & 0xFF)
+    uint16_t const hi = ((wordInt >> 48) & 0xFF);
     uint16_t const mh = ((wordInt >> 32) & 0xFF);
     uint16_t const ml = ((wordInt >> 24) & 0xFF);
     uint16_t const lo = ((wordInt >>  0) & 0xFF);
