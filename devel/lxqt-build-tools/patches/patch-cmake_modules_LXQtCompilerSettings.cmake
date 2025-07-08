$NetBSD: patch-cmake_modules_LXQtCompilerSettings.cmake,v 1.6 2025/07/08 01:54:40 gutteridge Exp $

Avoid -Bsymbolic* on SunOS.

Only require C++17; C++20 is not required for any dependent components
in the present state of pkgsrc.

--- cmake/modules/LXQtCompilerSettings.cmake.orig	2025-06-21 10:41:45.000000000 +0000
+++ cmake/modules/LXQtCompilerSettings.cmake
@@ -164,7 +164,11 @@ if (CMAKE_COMPILER_IS_GNUCXX OR LXQT_COM
         set(NO_UNDEFINED_FLAGS "-Wl,--no-undefined")
         # -Bsymbolic-functions: replace dynamic symbols used internally in
         #                       shared libs with direct addresses.
-        set(SYMBOLIC_FLAGS "-Wl,-Bsymbolic-functions")
+        if(${CMAKE_SYSTEM_NAME} STREQUAL "SunOS")
+            set(SYMBOLIC_FLAGS "")
+        else()
+            set(SYMBOLIC_FLAGS "-Wl,-Bsymbolic-functions")
+        endif()
     endif()
 
     set(CMAKE_SHARED_LINKER_FLAGS
@@ -181,11 +185,11 @@ endif()
 
 
 #-----------------------------------------------------------------------------
-# CXX20 requirements - no checks, we just set it
+# CXX17 requirements - no checks, we just set it
 #-----------------------------------------------------------------------------
 set(CMAKE_CXX_STANDARD_REQUIRED True)
 set(CMAKE_CXX_EXTENSIONS OFF)
-set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ ISO Standard")
+set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ ISO Standard")
 
 
 #-----------------------------------------------------------------------------
