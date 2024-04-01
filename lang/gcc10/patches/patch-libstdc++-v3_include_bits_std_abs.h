$NetBSD: patch-libstdc++-v3_include_bits_std_abs.h,v 1.1 2024/04/01 14:33:58 js Exp $

--- libstdc++-v3/include/bits/std_abs.h.orig	2023-07-07 07:08:22.000000000 +0000
+++ libstdc++-v3/include/bits/std_abs.h
@@ -41,6 +41,10 @@
 #endif
 #undef _GLIBCXX_INCLUDE_NEXT_C_HEADERS
 
+#ifdef __QNX__
+#define __CORRECT_ISO_CPP_MATH_H_PROTO
+#endif
+
 #undef abs
 
 extern "C++"
