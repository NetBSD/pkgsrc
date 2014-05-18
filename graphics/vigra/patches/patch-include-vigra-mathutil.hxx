$NetBSD: patch-include-vigra-mathutil.hxx,v 1.4 2014/05/18 11:31:09 adam Exp $

* missing abs(signed long long) in old GCC.
* Fix ambiguous math functions for DragonFly.

--- include/vigra/mathutil.hxx.orig	2013-11-18 16:48:16.000000000 +0000
+++ include/vigra/mathutil.hxx
@@ -153,7 +153,7 @@ VIGRA_DEFINE_UNSIGNED_ABS(unsigned long 
 VIGRA_DEFINE_MISSING_ABS(signed char)
 VIGRA_DEFINE_MISSING_ABS(signed short)
 
-#if defined(_MSC_VER) && _MSC_VER < 1600
+#if defined(_MSC_VER) && _MSC_VER < 1600 || defined(__GNUC__) && (__GNUC__ < 4 || __GNUC__ == 4 && __GNUC_MINOR__ < 2)
 VIGRA_DEFINE_MISSING_ABS(signed long long)
 #endif
 
@@ -637,7 +637,12 @@ VIGRA_DEFINE_NORM(int)
 VIGRA_DEFINE_NORM(unsigned int)
 VIGRA_DEFINE_NORM(long)
 VIGRA_DEFINE_NORM(unsigned long)
+#if defined(__DragonFly__)
+inline NormTraits<long long>::SquaredNormType squaredNorm(long long t) { return sq((long int) t); }
+inline NormTraits<long long>::NormType norm(long long t) { return abs((long int) t); }
+#else
 VIGRA_DEFINE_NORM(long long)
+#endif
 VIGRA_DEFINE_NORM(unsigned long long)
 VIGRA_DEFINE_NORM(float)
 VIGRA_DEFINE_NORM(double)
