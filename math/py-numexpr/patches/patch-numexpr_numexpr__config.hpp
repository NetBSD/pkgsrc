$NetBSD: patch-numexpr_numexpr__config.hpp,v 1.1 2025/09/14 14:03:44 wiz Exp $

Fix build on NetBSD.
https://github.com/pydata/numexpr/issues/528

--- numexpr/numexpr_config.hpp.orig	2025-09-14 13:57:31.046041558 +0000
+++ numexpr/numexpr_config.hpp
@@ -40,6 +40,7 @@
 #include "mkl_vml.h"
 #include "mkl_service.h"
 #endif
+#include <cmath>
 
 #ifdef _WIN32
   #ifndef __MINGW32__
@@ -51,12 +52,12 @@
 msvc_function_stubs contains windows alternatives
 /* Due to casting problems (normally return ints not bools, easiest to define
 non-overloaded wrappers for these functions) */
-inline bool isfinitef_(float x) { return !!::isfinite(x); }
-inline bool isnanf_(float x)    { return !!::isnan(x); }
-inline bool isfinited(double x) { return !!::isfinite(x); }
-inline bool isnand(double x)    { return !!::isnan(x); }
-inline bool isinff_(float x) { return !!::isinf(x); }
-inline bool isinfd(double x)    { return !!::isinf(x); }
+inline bool isfinitef_(float x) { return !!std::isfinite(x); }
+inline bool isnanf_(float x)    { return !!std::isnan(x); }
+inline bool isfinited(double x) { return !!std::isfinite(x); }
+inline bool isnand(double x)    { return !!std::isnan(x); }
+inline bool isinff_(float x) { return !!std::isinf(x); }
+inline bool isinfd(double x)    { return !!std::isinf(x); }
 #endif
 
 #endif // NUMEXPR_CONFIG_HPP
