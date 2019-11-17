$NetBSD: patch-src_openrct2_Version.h,v 1.1 2019/11/17 16:19:57 nia Exp $

Support NetBSD.

--- src/openrct2/Version.h.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2/Version.h
@@ -56,6 +56,9 @@
 #ifdef __FreeBSD__
 #    define OPENRCT2_PLATFORM "FreeBSD"
 #endif
+#ifdef __NetBSD__
+#    define OPENRCT2_PLATFORM "NetBSD"
+#endif
 #ifdef __ANDROID__
 #    define OPENRCT2_PLATFORM "Android"
 #endif
