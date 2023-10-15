$NetBSD: patch-src_hrtf_portable__endian.h,v 1.1 2023/10/15 19:33:54 adam Exp $

Fix build on NetBSD.
https://github.com/hoene/libmysofa/issues/211

--- src/hrtf/portable_endian.h.orig	2023-10-15 19:23:14.526442578 +0000
+++ src/hrtf/portable_endian.h
@@ -41,11 +41,11 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
 
 #	include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 #	include <sys/endian.h>
 
