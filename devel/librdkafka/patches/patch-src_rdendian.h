$NetBSD: patch-src_rdendian.h,v 1.1 2017/04/24 12:20:37 fhajny Exp $

Add NetBSD support.

--- src/rdendian.h.orig	2017-04-12 08:36:34.000000000 +0000
+++ src/rdendian.h
@@ -38,7 +38,7 @@
  *   htobe16()
  */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   #include <sys/endian.h>
 #elif defined __GLIBC__
   #include <endian.h>
