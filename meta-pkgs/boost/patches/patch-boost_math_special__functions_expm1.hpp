$NetBSD: patch-boost_math_special__functions_expm1.hpp,v 1.2 2024/12/29 14:53:14 adam Exp $

--- boost/math/special_functions/expm1.hpp.orig	2024-12-05 00:53:33.000000000 +0000
+++ boost/math/special_functions/expm1.hpp
@@ -299,7 +299,7 @@ BOOST_MATH_GPU_ENABLED inline typename t
 #endif
 
 #if defined(BOOST_HAS_EXPM1) && !(defined(__osf__) && defined(__DECCXX_VER))
-#  ifdef BOOST_MATH_USE_C99
+#  if defined(BOOST_MATH_USE_C99) && !defined(__NetBSD__)
 BOOST_MATH_GPU_ENABLED inline float expm1(float x, const policies::policy<>&){ return ::expm1f(x); }
 #     ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
 inline long double expm1(long double x, const policies::policy<>&){ return ::expm1l(x); }
