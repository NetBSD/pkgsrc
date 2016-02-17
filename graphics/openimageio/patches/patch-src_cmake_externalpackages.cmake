$NetBSD: patch-src_cmake_externalpackages.cmake,v 1.1 2016/02/17 04:49:47 dbj Exp $

--- src/cmake/externalpackages.cmake.orig	2015-06-11 17:25:58.000000000 +0000
+++ src/cmake/externalpackages.cmake
@@ -467,7 +467,16 @@ if (USE_OPENCV)
                         /usr/local/lib
                         /opt/local/lib
                  )
-    set (OpenCV_LIBS "${OpenCV_LIBS} ${OpenCV_LIBS_highgui}")
+    set (OpenCV_LIBS ${OpenCV_LIBS} ${OpenCV_LIBS_highgui})
+    find_library (OpenCV_LIBS_videoio
+                  NAMES opencv_videoio
+                  PATHS "${THIRD_PARTY_TOOLS_HOME}/lib/"
+                        "${PROJECT_SOURCE_DIR}/lib"
+                        "${OpenCV_HOME}/lib"
+                        /usr/local/lib
+                        /opt/local/lib
+                 )
+    set (OpenCV_LIBS ${OpenCV_LIBS} ${OpenCV_LIBS_videoio})
     if (OpenCV_INCLUDE_DIR AND OpenCV_LIBS)
         set (OpenCV_FOUND TRUE)
         add_definitions ("-DUSE_OPENCV")
