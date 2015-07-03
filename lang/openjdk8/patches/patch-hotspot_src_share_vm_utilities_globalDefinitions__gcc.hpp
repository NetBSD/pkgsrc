$NetBSD: patch-hotspot_src_share_vm_utilities_globalDefinitions__gcc.hpp,v 1.3 2015/07/03 20:40:59 fhajny Exp $

--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2015-02-02 15:32:37.000000000 +0000
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
@@ -76,7 +76,7 @@
 # include <sys/procfs.h>
 # endif
 
-#if defined(LINUX) || defined(_ALLBSD_SOURCE)
+#if defined(LINUX) || defined(_ALLBSD_SOURCE) || defined(SOLARIS)
 #ifndef __STDC_LIMIT_MACROS
 #define __STDC_LIMIT_MACROS
 #endif // __STDC_LIMIT_MACROS
