$NetBSD: patch-hotspot_src_share_vm_utilities_globalDefinitions__gcc.hpp,v 1.1 2013/06/15 09:31:06 jperkin Exp $

SunOS fixes.

--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2013-02-19 23:21:59.000000000 +0000
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
