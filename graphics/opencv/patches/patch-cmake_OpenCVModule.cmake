$NetBSD: patch-cmake_OpenCVModule.cmake,v 1.2 2016/02/21 14:10:46 fhajny Exp $

Fix library id handling on Darwin

--- cmake/OpenCVModule.cmake.orig	2015-12-18 15:02:16.000000000 +0000
+++ cmake/OpenCVModule.cmake
@@ -834,7 +834,7 @@ macro(_ocv_create_module)
     COMPILE_PDB_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
     LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
     RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
-    INSTALL_NAME_DIR lib
+    INSTALL_NAME_DIR ${CMAKE_INSTALL_PREFIX}/${OPENCV_LIB_INSTALL_PATH}
   )
 
   # For dynamic link numbering convenions
