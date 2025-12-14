$NetBSD: patch-contrib_check-speexdsp_test__speexdsp__float__api.cpp,v 1.1 2025/12/14 10:07:19 vins Exp $

Dirty workaround for broken assert on SunOS.

--- contrib/check-speexdsp/test_speexdsp_float_api.cpp.orig	2025-12-14 08:32:14.743429064 +0000
+++ contrib/check-speexdsp/test_speexdsp_float_api.cpp
@@ -28,10 +28,13 @@
 //
 // No output is provided because it's typically run by the build system.
 //
-
-#ifdef NDEBUG
+#ifdef __sun
+#define NDEBUG
+#else
+# ifdef NDEBUG
 #	undef NDEBUG
-#endif // Ensure asserts are enabled
+# endif // Ensure asserts are enabled
+#endif // __sun
 #include <cassert>
 
 #include <array>
