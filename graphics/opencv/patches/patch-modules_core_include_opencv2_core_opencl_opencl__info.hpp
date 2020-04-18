$NetBSD: patch-modules_core_include_opencv2_core_opencl_opencl__info.hpp,v 1.1 2020/04/18 22:01:33 joerg Exp $

--- modules/core/include/opencv2/core/opencl/opencl_info.hpp.orig	2020-04-18 02:39:48.224336800 +0000
+++ modules/core/include/opencv2/core/opencl/opencl_info.hpp
@@ -3,6 +3,7 @@
 // of this distribution and at http://opencv.org/license.html.
 
 #include <iostream>
+#include <sstream>
 
 #include <opencv2/core.hpp>
 #include <opencv2/core/ocl.hpp>
