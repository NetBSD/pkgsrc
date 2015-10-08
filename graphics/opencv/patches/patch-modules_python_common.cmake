$NetBSD: patch-modules_python_common.cmake,v 1.1 2015/10/08 17:45:59 fhajny Exp $

Backport fix from https://github.com/Itseez/opencv/pull/4109

--- modules/python/common.cmake.orig	2015-06-03 17:21:34.000000000 +0000
+++ modules/python/common.cmake
@@ -28,6 +28,7 @@ endforeach(m)
 ocv_list_filterout(opencv_hdrs ".h$")
 ocv_list_filterout(opencv_hdrs "cuda")
 ocv_list_filterout(opencv_hdrs "cudev")
+ocv_list_filterout(opencv_hdrs "detection_based_tracker.hpp") # Conditional compilation
 
 set(cv2_generated_hdrs
     "${CMAKE_CURRENT_BINARY_DIR}/pyopencv_generated_include.h"
