$NetBSD: patch-src_build-system_cmake_cmake-cfg-xcode.sh,v 1.3 2023/05/28 22:48:27 bacon Exp $

# sh portability

--- src/build-system/cmake/cmake-cfg-xcode.sh.orig	2023-05-26 12:05:14.109542442 +0000
+++ src/build-system/cmake/cmake-cfg-xcode.sh
@@ -249,12 +249,12 @@ CMAKE_ARGS="$CMAKE_ARGS -DBUILD_SHARED_L
 if [ -z "$BUILD_ROOT" ]; then
   if [ -z "$BUILD_TYPE" ]; then
     BUILD_ROOT=CMake-${CC_NAME}${CC_VERSION}
-    if [ "$BUILD_SHARED_LIBS" == "ON" ]; then
+    if [ "$BUILD_SHARED_LIBS" = "ON" ]; then
       BUILD_ROOT="$BUILD_ROOT"-DLL
     fi
   else
     BUILD_ROOT=CMake-${CC_NAME}${CC_VERSION}-${BUILD_TYPE}
-    if [ "$BUILD_SHARED_LIBS" == "ON" ]; then
+    if [ "$BUILD_SHARED_LIBS" = "ON" ]; then
       BUILD_ROOT="$BUILD_ROOT"DLL
     fi
   fi
