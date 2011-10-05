$NetBSD: patch-src_d__osc.c,v 1.2 2011/10/05 20:02:48 wiz Exp $

Detect endianness on NetBSD.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

--- src/d_osc.c.orig	2010-07-28 20:55:17.000000000 +0000
+++ src/d_osc.c
@@ -15,7 +15,7 @@
 #include <sys/endian.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #include <machine/endian.h>
 #endif
 
