$NetBSD: patch-hotspot_src_share_vm_utilities_globalDefinitions__gcc.hpp,v 1.1 2015/03/01 21:43:50 tnn Exp $

--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2015-02-02 15:32:37.000000000 +0000
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
