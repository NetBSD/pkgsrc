$NetBSD: patch-src_ortho_mcode_memsegs__c.c,v 1.1 2022/05/19 16:05:12 ryoon Exp $

* Support NetBSD for mcode backend. (not used)

--- src/ortho/mcode/memsegs_c.c.orig	2022-02-28 18:46:53.000000000 +0000
+++ src/ortho/mcode/memsegs_c.c
@@ -28,6 +28,8 @@
 
 #if defined(__APPLE__) || defined(__OpenBSD__)
 #define MAP_ANONYMOUS MAP_ANON
+#elif defined(__NetBSD__)
+/* nothing */
 #else
 #define HAVE_MREMAP
 #endif
