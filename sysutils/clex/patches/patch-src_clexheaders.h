$NetBSD: patch-src_clexheaders.h,v 1.2 2026/06/24 11:53:10 drixter Exp $

 
 * Need to treat *BSD same as FreeBSD.
 

--- src/clexheaders.h.orig	2026-06-24 08:43:18.387468661 +0000
+++ src/clexheaders.h
@@ -1,6 +1,6 @@
 #if defined(__APPLE__)
 # define _XOPEN_SOURCE_EXTENDED
-#elif !defined(__FreeBSD__)
+#elif !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 # define _XOPEN_SOURCE 600
 #endif
