$NetBSD: patch-src_multiply.h,v 1.1 2018/03/08 08:15:02 adam Exp $

Avoid conflicting types.

--- src/multiply.h.orig	2018-03-08 07:51:51.000000000 +0000
+++ src/multiply.h
@@ -59,7 +59,7 @@ __attribute__((optimize("-O3")))
 #endif
 ;
 
-size_t addmul128(uint64_t * RESTRICT t, const uint64_t * RESTRICT a, uint64_t b0, uint64_t b1, size_t words)
+uint64_t addmul128(uint64_t * RESTRICT t, const uint64_t * RESTRICT a, uint64_t b0, uint64_t b1, size_t words)
 #if defined(__GNUC__) && !defined(__clang__)
 __attribute__((optimize("-O3")))
 #endif
