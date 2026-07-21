$NetBSD: patch-src_runtime_config.h,v 1.1 2026/07/21 14:07:29 ryoon Exp $

--- src/runtime/config.h.orig	2026-06-03 12:59:35.006483455 +0000
+++ src/runtime/config.h
@@ -18,6 +18,7 @@
 
 /* Library dependencies */
 
+#if !defined(__NetBSD__)
 #ifdef HAS_MEMMOVE
 #define bcopy(src,dst,len) memmove((dst), (src), (len))
 #else
@@ -29,6 +30,7 @@
 #else
 #define bcopy(src,dst,len) memmov((dst), (src), (len))
 #define USING_MEMMOV
+#endif
 #endif
 #endif
 #endif
