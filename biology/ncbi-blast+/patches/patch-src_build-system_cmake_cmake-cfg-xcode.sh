$NetBSD: patch-src_build-system_cmake_cmake-cfg-xcode.sh,v 1.2 2022/04/10 20:54:51 bacon Exp $

# Portability

--- src/build-system/cmake/cmake-cfg-xcode.sh.orig	2021-06-10 11:54:05.800996703 +0000
+++ src/build-system/cmake/cmake-cfg-xcode.sh
@@ -218,7 +218,7 @@ CMAKE_ARGS="$CMAKE_ARGS -DBUILD_SHARED_L
 
 if [ -z "$BUILD_ROOT" ]; then
   BUILD_ROOT=CMake-${CC_NAME}${CC_VERSION}
-  if [ "$BUILD_SHARED_LIBS" == "ON" ]; then
+  if [ "$BUILD_SHARED_LIBS" = "ON" ]; then
     BUILD_ROOT="$BUILD_ROOT"-DLL
   fi
 fi
