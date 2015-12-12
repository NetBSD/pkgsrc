$NetBSD: patch-removeredeyes_plugin_libopencv.h,v 1.1 2015/12/12 19:32:45 markd Exp $

opencv3 support. https://bugs.kde.org/show_bug.cgi?id=349601

--- removeredeyes/plugin/libopencv.h.orig	2015-09-03 21:22:45.000000000 +0000
+++ removeredeyes/plugin/libopencv.h
@@ -7,7 +7,7 @@
  * @date   2010-06-16
  * @brief  Wrapper for OpenCV header files
  *
- * @author Copyright (C) 2012-2014 by Gilles Caulier
+ * @author Copyright (C) 2012-2015 by Gilles Caulier
  *         <a href="mailto:caulier dot gilles at gmail dot com">caulier dot gilles at gmail dot com</a>
  *
  * This program is free software; you can redistribute it
@@ -53,12 +53,13 @@
 
 #define OPENCV_MAKE_VERSION(major,minor,patch) (((major) << 16) | ((minor) << 8) | (patch))
 #define OPENCV_VERSION                         OPENCV_MAKE_VERSION(CV_MAJOR_VERSION,CV_MINOR_VERSION,CV_SUBMINOR_VERSION)
-#define OPENCV_TEST_VERSION(major,minor,patch) ( OPENCV_VERSION >= OPENCV_MAKE_VERSION(major,minor,patch) )
+#define OPENCV_TEST_VERSION(major,minor,patch) ( OPENCV_VERSION < OPENCV_MAKE_VERSION(major,minor,patch) )
 
-#if OPENCV_TEST_VERSION(2,3,0)
+#include <opencv2/core/core_c.h>
+
+#if OPENCV_TEST_VERSION(2,5,0)
 #include <opencv2/opencv.hpp>
 #include <opencv2/highgui/highgui_c.h>
-#include <opencv2/core/core_c.h>
 #include <opencv2/legacy/compat.hpp>
 #include <opencv/cvaux.h>
 #else
