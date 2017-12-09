$NetBSD: patch-src_rdendian.h,v 1.2 2017/12/09 16:57:04 fhajny Exp $

Add NetBSD support.

--- src/rdendian.h.orig	2017-12-04 09:29:22.000000000 +0000
+++ src/rdendian.h
@@ -39,7 +39,7 @@
  *   le64toh()
  */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   #include <sys/endian.h>
 #elif defined __GLIBC__
   #include <endian.h>
