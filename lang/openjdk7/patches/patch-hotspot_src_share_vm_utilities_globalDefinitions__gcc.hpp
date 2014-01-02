$NetBSD: patch-hotspot_src_share_vm_utilities_globalDefinitions__gcc.hpp,v 1.3 2014/01/02 01:16:35 ryoon Exp $

SunOS fixes.

--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2014-01-01 05:50:08.000000000 +0000
+++ hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp
@@ -31,6 +31,10 @@
 // globally used constants & types, class (forward)
 // declarations and a few frequently used utility functions.
 
+#ifdef SOLARIS
+#include <inttypes.h>
+#endif // SOLARIS
+
 #include <ctype.h>
 #include <string.h>
 #include <stdarg.h>
@@ -241,6 +245,7 @@ extern "C" void breakpoint();
 #define BREAKPOINT ::breakpoint()
 #endif
 
+#include <sys/param.h> /* for __DragonFly_version */
 // checking for nanness
 #ifdef SOLARIS
 #ifdef SPARC
@@ -252,6 +257,9 @@ inline int g_isnan(float  f) { return is
 inline int g_isnan(double f) { return isnand(f); }
 #elif defined(__APPLE__)
 inline int g_isnan(double f) { return isnan(f); }
+#elif defined(__DragonFly__) && __DragonFly_version < 300500
+inline int g_isnan(float  f) { return __isnanf(f); }
+inline int g_isnan(double f) { return __isnand(f); }
 #elif defined(LINUX) || defined(_ALLBSD_SOURCE)
 inline int g_isnan(float  f) { return isnanf(f); }
 inline int g_isnan(double f) { return isnan(f); }
