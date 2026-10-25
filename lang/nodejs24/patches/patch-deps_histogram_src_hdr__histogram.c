$NetBSD: patch-deps_histogram_src_hdr__histogram.c,v 1.1.2.2 2026/10/25 09:16:51 bsiegert Exp $

* Fix build under NetBSD/i386.

--- deps/histogram/src/hdr_histogram.c.orig	2026-10-04 18:16:37.068569235 +0000
+++ deps/histogram/src/hdr_histogram.c
@@ -36,8 +36,8 @@
 
 /* Runtime-dispatched AVX2 path: keep the rest of this TU at the project's
    baseline ISA so the shipped binary does not silently require AVX2. */
-#if (defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)) \
-    && (defined(__GNUC__) || defined(__clang__)) && !defined(__INTEL_COMPILER) && !defined(_MSC_VER)
+#if (defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86)) \
+     && (defined(__GNUC__) || defined(__clang__)) && !defined(__INTEL_COMPILER) && !defined(_MSC_VER)
 #  define HDR_HAS_AVX2_DISPATCH 1
 #  include <immintrin.h>
 #endif
