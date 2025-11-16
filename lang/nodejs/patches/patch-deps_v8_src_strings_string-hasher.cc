$NetBSD: patch-deps_v8_src_strings_string-hasher.cc,v 1.1 2025/11/16 15:41:15 maya Exp $

Use the same conditional that compilers use to guard the definition of
_mm_cvtsi128_si64

Fixes build on i386.

--- deps/v8/src/strings/string-hasher.cc.orig	2025-11-16 13:13:35.855946341 +0000
+++ deps/v8/src/strings/string-hasher.cc
@@ -23,7 +23,7 @@ struct ConvertTo8BitHashReader {
     DCHECK_LE(p[5], 0xff);
     DCHECK_LE(p[6], 0xff);
     DCHECK_LE(p[7], 0xff);
-#ifdef __SSE2__
+#ifdef __x86_64__
     __m128i x = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
     return _mm_cvtsi128_si64(_mm_packus_epi16(x, x));
 #elif defined(__ARM_NEON__)
@@ -44,7 +44,7 @@ struct ConvertTo8BitHashReader {
     DCHECK_LE(p[1], 0xff);
     DCHECK_LE(p[2], 0xff);
     DCHECK_LE(p[3], 0xff);
-#ifdef __SSE2__
+#ifdef __x86_64__
     __m128i x = _mm_loadu_si64(reinterpret_cast<const __m128i*>(p));
     return _mm_cvtsi128_si64(_mm_packus_epi16(x, x));
 #elif defined(__ARM_NEON__)
