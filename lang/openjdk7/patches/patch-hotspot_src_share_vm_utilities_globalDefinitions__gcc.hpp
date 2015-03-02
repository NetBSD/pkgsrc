$NetBSD: patch-hotspot_src_share_vm_utilities_globalDefinitions__gcc.hpp,v 1.5 2015/03/02 03:53:26 tnn Exp $

--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2015-01-26 15:21:49.000000000 +0000
+++ hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp
@@ -76,7 +76,7 @@
 # include <sys/procfs.h>
 # endif
 
-#if defined(LINUX) || defined(_ALLBSD_SOURCE)
+#if defined(LINUX) || defined(_ALLBSD_SOURCE) || defined(SOLARIS)
 #ifndef __STDC_LIMIT_MACROS
 #define __STDC_LIMIT_MACROS
 #endif // __STDC_LIMIT_MACROS
