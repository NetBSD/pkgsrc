$NetBSD: patch-modules_flann_include_opencv2_flann_defines.h,v 1.1 2013/06/12 10:13:58 jperkin Exp $

Avoid CS conflict on SunOS.

--- modules/flann/include/opencv2/flann/defines.h.orig	2012-09-27 22:55:06.000000000 +0000
+++ modules/flann/include/opencv2/flann/defines.h
@@ -71,6 +71,9 @@
 #define FLANN_PLATFORM_32_BIT
 #endif
 
+#ifdef __sun
+#undef CS
+#endif
 
 #undef FLANN_ARRAY_LEN
 #define FLANN_ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))
