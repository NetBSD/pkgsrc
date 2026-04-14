$NetBSD: patch-src_basic_alloc-util.h,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Add NetBSD support

--- src/basic/alloc-util.h.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/basic/alloc-util.h
@@ -38,7 +38,7 @@ static inline void *mfree(void *memory) 
                 0;                              \
         })
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define mempcpy __builtin_mempcpy
 #endif
 
