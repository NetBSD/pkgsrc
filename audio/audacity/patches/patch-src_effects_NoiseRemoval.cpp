$NetBSD: patch-src_effects_NoiseRemoval.cpp,v 1.2 2015/04/20 13:38:23 rodent Exp $

Fix build for SunOS.

--- src/effects/NoiseRemoval.cpp.orig	2015-03-02 01:06:57.000000000 +0000
+++ src/effects/NoiseRemoval.cpp
@@ -50,6 +50,10 @@
 
 #include <math.h>
 
+#ifdef __sun
+#include <ieeefp.h>
+#endif
+
 #if defined(__WXMSW__) && !defined(__CYGWIN__)
 #include <float.h>
 #define finite(x) _finite(x)
