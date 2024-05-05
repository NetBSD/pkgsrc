$NetBSD: patch-cmake_pcl__targets.cmake,v 1.1 2024/05/05 20:58:08 adam Exp $

On Darwin, do not make application bundles.

--- cmake/pcl_targets.cmake.orig	2024-05-05 18:48:22.260824422 +0000
+++ cmake/pcl_targets.cmake
@@ -316,11 +316,7 @@ function(PCL_ADD_EXECUTABLE _name)
     message(FATAL_ERROR "PCL_ADD_EXECUTABLE requires parameter COMPONENT.")
   endif()
 
-  if(ARGS_BUNDLE AND APPLE AND VTK_USE_COCOA)
-    add_executable(${_name} MACOSX_BUNDLE ${ARGS_SOURCES})
-  else()
-    add_executable(${_name} ${ARGS_SOURCES})
-  endif()
+  add_executable(${_name} ${ARGS_SOURCES})
   PCL_ADD_VERSION_INFO(${_name})
 
   target_link_libraries(${_name} Threads::Threads)
