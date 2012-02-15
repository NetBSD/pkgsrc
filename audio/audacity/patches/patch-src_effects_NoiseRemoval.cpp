--- src/effects/NoiseRemoval.cpp.orig	2006-11-15 05:12:10.000000000 +0100
+++ src/effects/NoiseRemoval.cpp	2012-01-15 19:19:20.622909031 +0100
@@ -16,6 +16,10 @@
 
 #include <math.h>
 
+#ifdef __sun
+#include <ieeefp.h>
+#endif
+
 #if defined(__WXMSW__) && !defined(__CYGWIN__)
 #include <float.h>
 #define finite(x) _finite(x)
