$NetBSD: patch-hotspot_src_share_vm_utilities_globalDefinitions__gcc.hpp,v 1.4 2015/03/01 21:44:29 tnn Exp $

--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2015-01-26 15:21:49.000000000 +0000
+++ hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp
@@ -31,6 +31,16 @@
 // globally used constants & types, class (forward)
 // declarations and a few frequently used utility functions.
 
+#ifndef __STDC_CONSTANT_MACROS
+#define __STDC_CONSTANT_MACROS
+#endif
+#ifndef __STDC_FORMAT_MACROS
+#define __STDC_FORMAT_MACROS
+#endif
+#ifndef __STDC_LIMIT_MACROS
+#define __STDC_LIMIT_MACROS
+#endif
+
 #include <ctype.h>
 #include <string.h>
 #include <stdarg.h>
@@ -76,10 +86,7 @@
 # include <sys/procfs.h>
 # endif
 
-#if defined(LINUX) || defined(_ALLBSD_SOURCE)
-#ifndef __STDC_LIMIT_MACROS
-#define __STDC_LIMIT_MACROS
-#endif // __STDC_LIMIT_MACROS
+#if defined(LINUX) || defined(_ALLBSD_SOURCE) || defined(SOLARIS)
 #include <inttypes.h>
 #include <signal.h>
 #ifndef __OpenBSD__
@@ -241,6 +248,7 @@ extern "C" void breakpoint();
 #define BREAKPOINT ::breakpoint()
 #endif
 
+#include <sys/param.h> /* for __DragonFly_version */
 // checking for nanness
 #ifdef SOLARIS
 #ifdef SPARC
@@ -252,6 +260,9 @@ inline int g_isnan(float  f) { return is
 inline int g_isnan(double f) { return isnand(f); }
 #elif defined(__APPLE__)
 inline int g_isnan(double f) { return isnan(f); }
+#elif defined(__DragonFly__) && __DragonFly_version < 300500
+inline int g_isnan(float  f) { return __isnanf(f); }
+inline int g_isnan(double f) { return __isnand(f); }
 #elif defined(LINUX) || defined(_ALLBSD_SOURCE)
 inline int g_isnan(float  f) { return isnanf(f); }
 inline int g_isnan(double f) { return isnan(f); }
