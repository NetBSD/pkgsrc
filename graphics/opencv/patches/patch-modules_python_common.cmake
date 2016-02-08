$NetBSD: patch-modules_python_common.cmake,v 1.2 2016/02/08 02:04:18 dbj Exp $

Backport fix from https://github.com/Itseez/opencv/pull/4109
Also, fix library id handling on Darwin

--- modules/python/common.cmake.orig	2015-06-03 17:21:34.000000000 +0000
+++ modules/python/common.cmake
@@ -28,6 +28,7 @@ endforeach(m)
 ocv_list_filterout(opencv_hdrs ".h$")
 ocv_list_filterout(opencv_hdrs "cuda")
 ocv_list_filterout(opencv_hdrs "cudev")
+ocv_list_filterout(opencv_hdrs "detection_based_tracker.hpp") # Conditional compilation
 
 set(cv2_generated_hdrs
     "${CMAKE_CURRENT_BINARY_DIR}/pyopencv_generated_include.h"
@@ -45,7 +46,7 @@ add_custom_command(
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/headers.txt
    DEPENDS ${opencv_hdrs})
 
-ocv_add_library(${the_module} SHARED ${PYTHON_SOURCE_DIR}/src2/cv2.cpp ${cv2_generated_hdrs})
+ocv_add_library(${the_module} MODULE ${PYTHON_SOURCE_DIR}/src2/cv2.cpp ${cv2_generated_hdrs})
 
 if(PYTHON_DEBUG_LIBRARIES AND NOT PYTHON_LIBRARIES MATCHES "optimized.*debug")
   ocv_target_link_libraries(${the_module} debug ${PYTHON_DEBUG_LIBRARIES} optimized ${PYTHON_LIBRARIES})
