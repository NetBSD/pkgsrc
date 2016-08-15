$NetBSD: patch-hotspot_src_share_vm_utilities_globalDefinitions__gcc.hpp,v 1.4 2016/08/15 19:09:38 ryoon Exp $

--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2016-08-11 05:37:42.000000000 +0000
+++ hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp
@@ -30,12 +30,16 @@
 // This file holds compiler-dependent includes,
 // globally used constants & types, class (forward)
 // declarations and a few frequently used utility functions.
-#if defined(LINUX) || defined(_ALLBSD_SOURCE)
+#if defined(LINUX) || defined(_ALLBSD_SOURCE) || defined(SOLARIS)
 #ifndef __STDC_LIMIT_MACROS
 #define __STDC_LIMIT_MACROS
 #endif // __STDC_LIMIT_MACROS
 #endif
 
+#ifdef SOLARIS
+#include <inttypes.h>
+#endif // SOLARIS
+
 #include <ctype.h>
 #include <string.h>
 #include <stdarg.h>
