$NetBSD: patch-core_cmake_BareosFindAllLibraries.cmake,v 1.3 2023/01/13 11:50:37 jperkin Exp $

Prefer python3, remove broken SunOS section.

--- core/cmake/BareosFindAllLibraries.cmake.orig	2021-06-10 15:37:18.000000000 +0000
+++ core/cmake/BareosFindAllLibraries.cmake
@@ -30,12 +30,6 @@ if(${CMAKE_SYSTEM_NAME} MATCHES "Windows
   set(Python3_FOUND 1)
   set(Python3_EXT_SUFFIX ".pyd")
 
-  # Python Plugins currently cannot be built for Solaris
-elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-  set(HAVE_PYTHON 0)
-  set(Python2_FOUND 0)
-  set(Python3_FOUND 0)
-
 else()
   find_package(Python2 COMPONENTS Interpreter Development)
   find_package(Python3 COMPONENTS Interpreter Development)
@@ -54,7 +48,7 @@ else()
     set(HAVE_PYTHON 1)
   endif()
 
-  if(${Python2_FOUND})
+  if(${Python2_FOUND} AND NOT ${Python3_FOUND})
     set(PYTHON_EXECUTABLE
         ${Python2_EXECUTABLE}
         PARENT_SCOPE
@@ -72,6 +66,7 @@ else()
   endif()
 
   if(${Python3_FOUND})
+    set(Python2_FOUND 0)
     set(PYTHON_EXECUTABLE
         ${Python3_EXECUTABLE}
         PARENT_SCOPE
