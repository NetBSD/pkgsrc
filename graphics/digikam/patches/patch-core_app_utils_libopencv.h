$NetBSD: patch-core_app_utils_libopencv.h,v 1.1 2015/11/03 20:47:48 markd Exp $

opencv3 support. https://bugs.kde.org/show_bug.cgi?id=349601

--- core/app/utils/libopencv.h.orig	2015-09-03 21:22:45.000000000 +0000
+++ core/app/utils/libopencv.h
@@ -7,7 +7,7 @@
  * @date   2010-06-16
  * @brief  Wrapper for OpenCV header files
  *
- * @author Copyright (C) 2012-2014 by Gilles Caulier
+ * @author Copyright (C) 2012-2015 by Gilles Caulier
  *         <a href="mailto:caulier dot gilles at gmail dot com">caulier dot gilles at gmail dot com</a>
  *
  * This program is free software; you can redistribute it
@@ -46,17 +46,19 @@
 
 #define OPENCV_MAKE_VERSION(major,minor,patch) (((major) << 16) | ((minor) << 8) | (patch))
 #define OPENCV_VERSION                         OPENCV_MAKE_VERSION(CV_MAJOR_VERSION,CV_MINOR_VERSION,CV_SUBMINOR_VERSION)
-#define OPENCV_TEST_VERSION(major,minor,patch) ( OPENCV_VERSION >= OPENCV_MAKE_VERSION(major,minor,patch) )
+#define OPENCV_TEST_VERSION(major,minor,patch) ( OPENCV_VERSION < OPENCV_MAKE_VERSION(major,minor,patch) )
 
-#if OPENCV_TEST_VERSION(2,3,0)
+#if OPENCV_TEST_VERSION(2,5,0)
 #   include <opencv2/opencv.hpp>
 #   include <opencv2/legacy/compat.hpp>
 #   include <opencv/cvaux.h>
+#   include <opencv2/imgproc/imgproc.hpp>
 #else
 #   include <opencv/cv.h>
 #   include <opencv/cvaux.h>
 #   include <opencv/cxcore.h>
 #   include <opencv/highgui.h>
+#   include <opencv2/imgproc.hpp>
 #endif
 
 // Restore warnings
