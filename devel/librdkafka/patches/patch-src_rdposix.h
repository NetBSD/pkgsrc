$NetBSD: patch-src_rdposix.h,v 1.1 2017/04/24 12:20:37 fhajny Exp $

Add NetBSD support.

--- src/rdposix.h.orig	2017-04-12 08:36:34.000000000 +0000
+++ src/rdposix.h
@@ -63,7 +63,7 @@
 /**
 * Allocation
 */
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 /* alloca(3) is in stdlib on FreeBSD */
 #include <alloca.h>
 #endif
