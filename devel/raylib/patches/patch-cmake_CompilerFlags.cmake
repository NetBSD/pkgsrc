$NetBSD: patch-cmake_CompilerFlags.cmake,v 1.1 2023/07/11 23:46:57 charlotte Exp $

Allow for static linking.

--- cmake/CompilerFlags.cmake.orig	2021-04-26 09:00:33.000000000 -0700
+++ cmake/CompilerFlags.cmake	2021-05-01 01:51:08.410299439 -0700
@@ -77,3 +77,7 @@
     # https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html
     add_if_flag_compiles(-no-canonical-prefixes CMAKE_C_FLAGS)
 endif()
+
+if("${CMAKE_SYSTEM_NAME}" STREQUAL "NetBSD")
+  add_if_flag_compiles(-fPIC CMAKE_C_FLAGS)
+endif()
