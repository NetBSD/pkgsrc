$NetBSD: patch-cmake_modules_LXQtCompilerSettings.cmake,v 1.5 2024/08/02 16:52:38 pin Exp $

Avoid -Bsymbolic* on SunOS.

--- cmake/modules/LXQtCompilerSettings.cmake.orig	2024-05-27 05:52:17.311703304 +0000
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
