$NetBSD: patch-core_cmake_BareosFindAllLibraries.cmake,v 1.2 2021/02/01 09:08:43 kardel Exp $

	cmake build gets confused when both versions of python 2 and 3 are
	availabe. as python 2.7 is eol prefer python 3 in this case.

--- core/cmake/BareosFindAllLibraries.cmake.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/cmake/BareosFindAllLibraries.cmake
@@ -44,7 +44,7 @@ else()
     set(HAVE_PYTHON 1)
   endif()
 
-  if(${Python2_FOUND})
+  if(${Python2_FOUND} AND NOT ${Python3_FOUND})
     set(PYTHON_EXECUTABLE
         ${Python2_EXECUTABLE}
         PARENT_SCOPE
@@ -62,6 +62,7 @@ else()
   endif()
 
   if(${Python3_FOUND})
+    set(Python2_FOUND 0)
     set(PYTHON_EXECUTABLE
         ${Python3_EXECUTABLE}
         PARENT_SCOPE
