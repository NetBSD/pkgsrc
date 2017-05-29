$NetBSD: patch-src_third__party_IntelRDFPMathLib20U1_LIBRARY_src_bid__functions.h,v 1.1 2017/05/29 14:44:47 ryoon Exp $

--- src/third_party/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h.orig	2017-04-20 21:43:42.000000000 +0000
+++ src/third_party/IntelRDFPMathLib20U1/LIBRARY/src/bid_functions.h
@@ -159,7 +159,7 @@ typedef unsigned    long fexcept_t;
 typedef unsigned bid__int64 fexcept_t;
 #endif
 #else
-#ifdef __QNX__
+#if defined(__QNX__) || defined(__NetBSD__)
 #include <fenv.h>
 #else
 typedef unsigned short int fexcept_t;
