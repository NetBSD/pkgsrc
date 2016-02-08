$NetBSD: patch-cmake_OpenCVModule.cmake,v 1.1 2016/02/08 02:04:18 dbj Exp $

Fix library id handling on Darwin

--- cmake/OpenCVModule.cmake.orig	2015-06-03 17:21:34.000000000 +0000
+++ cmake/OpenCVModule.cmake
@@ -754,7 +754,7 @@ macro(_ocv_create_module)
     ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
     LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
     RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
-    INSTALL_NAME_DIR lib
+    INSTALL_NAME_DIR ${CMAKE_INSTALL_PREFIX}/${OPENCV_LIB_INSTALL_PATH}
   )
 
   # For dynamic link numbering convenions
