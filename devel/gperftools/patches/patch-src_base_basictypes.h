$NetBSD: patch-src_base_basictypes.h,v 1.3 2025/11/16 14:56:45 nia Exp $

Add support for NetBSD/powerpc, recognized via __powerpc__.

--- src/base/basictypes.h.orig	2025-02-17 16:34:39.000000000 +0000
+++ src/base/basictypes.h
@@ -150,7 +150,7 @@ inline void bit_store(Dest *dest, const 
 #if defined(HAVE___ATTRIBUTE__)
 # if (defined(__i386__) || defined(__x86_64__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(64)))
-# elif (defined(__PPC__) || defined(__PPC64__) || defined(__ppc__) || defined(__ppc64__))
+# elif (defined(__PPC__) || defined(__PPC64__) || defined(__ppc__) || defined(__ppc64__) || defined(__powerpc__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(16)))
 # elif (defined(__arm__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(64)))
@@ -166,6 +166,8 @@ inline void bit_store(Dest *dest, const 
 #   define CACHELINE_ALIGNED __attribute__((aligned(64)))
 # elif defined(__loongarch64)
 #   define CACHELINE_ALIGNED __attribute__((aligned(64)))
+# elif defined(__sparcv9) || defined(__sparcv9__)
+#   define CACHELINE_ALIGNED __attribute__((aligned(64)))
 # else
 #   error Could not determine cache line length - unknown architecture
 # endif
