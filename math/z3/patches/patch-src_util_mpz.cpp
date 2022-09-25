$NetBSD: patch-src_util_mpz.cpp,v 1.3 2022/09/25 11:01:34 he Exp $

<immintrin.h> is Intel-only(?)

--- src/util/mpz.cpp.orig	2018-11-19 20:21:17.000000000 +0000
+++ src/util/mpz.cpp
@@ -30,7 +30,9 @@ Revision History:
 #else
 #error No multi-precision library selected.
 #endif
+#if defined(_AMD64_) || defined(__i386__)
 #include <immintrin.h> 
+#endif
 
 // Available GCD algorithms
 // #define EUCLID_GCD
