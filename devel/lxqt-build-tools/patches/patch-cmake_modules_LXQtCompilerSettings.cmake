$NetBSD: patch-cmake_modules_LXQtCompilerSettings.cmake,v 1.1 2022/05/14 13:45:24 jperkin Exp $

Avoid -Bsymbolic* on SunOS.

--- cmake/modules/LXQtCompilerSettings.cmake.orig	2022-04-16 00:48:16.000000000 +0000
+++ cmake/modules/LXQtCompilerSettings.cmake
@@ -164,7 +164,11 @@ if (CMAKE_COMPILER_IS_GNUCXX OR LXQT_COM
         set(NO_UNDEFINED_FLAGS "-Wl,--no-undefined")
         # -Bsymbolic-functions: replace dynamic symbols used internally in
         #                       shared libs with direct addresses.
-        set(SYMBOLIC_FLAGS "-Wl,-Bsymbolic-functions -Wl,-Bsymbolic")
+        if(${CMAKE_SYSTEM_NAME} STREQUAL "SunOS")
+            set(SYMBOLIC_FLAGS "")
+        else()
+            set(SYMBOLIC_FLAGS "-Wl,-Bsymbolic-functions -Wl,-Bsymbolic")
+        endif()
     endif()
 
     set(CMAKE_SHARED_LINKER_FLAGS
