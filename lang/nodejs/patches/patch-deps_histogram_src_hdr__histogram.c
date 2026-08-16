$NetBSD: patch-deps_histogram_src_hdr__histogram.c,v 1.1 2026/08/16 11:56:45 ryoon Exp $

--- deps/histogram/src/hdr_histogram.c.orig	2026-08-16 07:43:18.222206955 +0000
+++ deps/histogram/src/hdr_histogram.c
@@ -36,7 +36,7 @@
 
 /* Runtime-dispatched AVX2 path: keep the rest of this TU at the project's
    baseline ISA so the shipped binary does not silently require AVX2. */
-#if (defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)) \
+#if (defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86)) \
     && (defined(__GNUC__) || defined(__clang__)) && !defined(__INTEL_COMPILER) && !defined(_MSC_VER)
 #  define HDR_HAS_AVX2_DISPATCH 1
 #  include <immintrin.h>
