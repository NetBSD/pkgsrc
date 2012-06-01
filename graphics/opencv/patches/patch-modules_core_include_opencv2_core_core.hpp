$NetBSD: patch-modules_core_include_opencv2_core_core.hpp,v 1.2 2012/06/01 21:24:57 wiz Exp $

Fix building on Mac OS X, where MIN and MAX got redefined by Obj-C headers.
http://code.opencv.org/issues/2011

--- modules/core/include/opencv2/core/core.hpp.orig	2012-04-03 17:44:46.000000000 +0000
+++ modules/core/include/opencv2/core/core.hpp
@@ -46,6 +46,12 @@
 #ifndef __OPENCV_CORE_HPP__
 #define __OPENCV_CORE_HPP__
 
+// make sure these are defined correctly
+#undef MIN
+#undef MAX
+#define MIN(a,b) (((a)<(b))?(a):(b))
+#define MAX(a,b) (((a)>(b))?(a):(b))
+
 #include "opencv2/core/types_c.h"
 #include "opencv2/core/version.hpp"
 
