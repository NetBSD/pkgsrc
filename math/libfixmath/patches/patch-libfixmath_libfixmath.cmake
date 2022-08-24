$NetBSD: patch-libfixmath_libfixmath.cmake,v 1.1 2022/08/24 12:49:24 ryoon Exp $

* Honor BUILD_SHARED_LIBS.
* install libraries and header files.

--- libfixmath/libfixmath.cmake.orig	2022-06-23 05:57:58.000000000 +0000
+++ libfixmath/libfixmath.cmake
@@ -1,3 +1,8 @@
-file(GLOB libfixmath-srcs libfixmath/*.h libfixmath/*.hpp libfixmath/*.c)
+file(GLOB libfixmath-srcs libfixmath/*.c)
+file(GLOB libfixmath-includes libfixmath/*.h libfixmath/*.hpp)
 
-add_library(libfixmath STATIC ${libfixmath-srcs})
+add_library(libfixmath ${libfixmath-srcs})
+target_include_directories(libfixmath INTERFACE
+	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libfixmath>
+	$<INSTALL_INTERFACE:include>
+)
