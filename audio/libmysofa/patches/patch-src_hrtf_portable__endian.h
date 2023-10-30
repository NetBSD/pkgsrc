$NetBSD: patch-src_hrtf_portable__endian.h,v 1.2 2023/10/30 16:15:32 jperkin Exp $

Fix build on NetBSD.
https://github.com/hoene/libmysofa/issues/211

--- src/hrtf/portable_endian.h.orig	2023-10-15 10:30:14.000000000 +0000
+++ src/hrtf/portable_endian.h
@@ -13,7 +13,7 @@
 
 #endif
 
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__sun)
 
 #	include <endian.h>
 
@@ -41,11 +41,11 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
 
 #	include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 #	include <sys/endian.h>
 
