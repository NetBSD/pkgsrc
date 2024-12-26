$NetBSD: patch-src_base_basictypes.h,v 1.2 2024/12/26 17:17:42 adam Exp $

Add support for NetBSD/powerpc, recognized via __powerpc__.

--- src/base/basictypes.h.orig	2024-09-20 20:51:40.000000000 +0000
+++ src/base/basictypes.h
@@ -200,7 +200,7 @@ inline void bit_store(Dest *dest, const
 #if defined(HAVE___ATTRIBUTE__)
 # if (defined(__i386__) || defined(__x86_64__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(64)))
-# elif (defined(__PPC__) || defined(__PPC64__) || defined(__ppc__) || defined(__ppc64__))
+# elif (defined(__PPC__) || defined(__PPC64__) || defined(__ppc__) || defined(__ppc64__) || defined(__powerpc__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(16)))
 # elif (defined(__arm__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(64)))
