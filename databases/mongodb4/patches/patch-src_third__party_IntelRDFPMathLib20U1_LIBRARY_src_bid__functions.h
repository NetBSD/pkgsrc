$NetBSD: patch-src_third__party_IntelRDFPMathLib20U1_LIBRARY_src_bid__functions.h,v 1.2 2024/06/07 17:39:01 abs Exp $

Fix buidling.

--- src/third_party/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h.orig	2019-01-30 14:26:33.000000000 +0000
+++ src/third_party/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h
@@ -164,7 +164,7 @@ typedef unsigned    long fexcept_t;
 typedef unsigned bid__int64 fexcept_t;
 #endif
 #else
-#if defined(__QNX__) || defined(__OpenBSD__)
+#if defined(__QNX__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <fenv.h>
 #else
 typedef unsigned short int fexcept_t;
