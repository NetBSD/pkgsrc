$NetBSD: patch-src_build-system_cmake_cmake-cfg-unix.sh,v 1.1 2019/01/07 15:00:10 bacon Exp $

# Portability

--- src/build-system/cmake/cmake-cfg-unix.sh.orig	2019-01-02 01:22:44.549100012 +0000
+++ src/build-system/cmake/cmake-cfg-unix.sh
@@ -166,7 +166,7 @@ CMAKE_ARGS="$CMAKE_ARGS -DBUILD_SHARED_L
 CMAKE_ARGS="$CMAKE_ARGS -DCMAKE_USE_CCACHE=$USE_CCACHE"
 CMAKE_ARGS="$CMAKE_ARGS -DCMAKE_USE_DISTCC=$USE_DISTCC"
 build_root=CMake-${CC_NAME}${CC_VERSION}-${BUILD_TYPE}
-if [ "$BUILD_SHARED_LIBS" == "ON" ]; then
+if [ "$BUILD_SHARED_LIBS" = "ON" ]; then
   build_root="$build_root"DLL
 fi
 #build_root="$build_root"64
