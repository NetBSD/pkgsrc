$NetBSD: patch-src_base_basictypes.h,v 1.1 2022/09/18 19:28:23 he Exp $

Add support for NetBSD/powerpc, recognized via __powerpc__.

--- src/base/basictypes.h.orig	2022-05-31 03:32:13.000000000 +0000
+++ src/base/basictypes.h
@@ -371,7 +371,7 @@ class AssignAttributeStartEnd {
 #if defined(HAVE___ATTRIBUTE__)
 # if (defined(__i386__) || defined(__x86_64__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(64)))
-# elif (defined(__PPC__) || defined(__PPC64__))
+# elif (defined(__PPC__) || defined(__PPC64__) || defined(__powerpc__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(16)))
 # elif (defined(__arm__))
 #   define CACHELINE_ALIGNED __attribute__((aligned(64)))
