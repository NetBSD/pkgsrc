$NetBSD: patch-bj,v 1.1 2009/10/18 10:21:01 tnn Exp $

--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2009-10-17 16:49:37.000000000 +0200
+++ hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp
@@ -243,6 +243,9 @@ inline int g_isnan(float  f) { return is
 inline int g_isnan(double f) { return isnand(f); }
 #elif defined(__APPLE__)
 inline int g_isnan(double f) { return isnan(f); }
+#elif defined(__DragonFly__)
+inline int g_isnan(float  f) { return __isnanf(f); }
+inline int g_isnan(double f) { return __isnand(f); }
 #elif defined(LINUX) || defined(_ALLBSD_SOURCE)
 inline int g_isnan(float  f) { return isnanf(f); }
 inline int g_isnan(double f) { return isnan(f); }
