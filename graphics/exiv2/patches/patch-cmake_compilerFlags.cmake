$NetBSD: patch-cmake_compilerFlags.cmake,v 1.1 2020/09/10 11:31:58 martin Exp $

Gcc on sparc* does not support -fcf-protection.

--- cmake/compilerFlags.cmake.orig	2020-06-30 15:33:22.000000000 +0200
+++ cmake/compilerFlags.cmake	2020-09-10 13:20:12.412480808 +0200
@@ -25,7 +25,7 @@
 
         # This fails under Fedora, MinGW GCC 8.3.0 and CYGWIN/MSYS 9.3.0
         if (NOT (MINGW OR CMAKE_HOST_SOLARIS OR CYGWIN OR MSYS) )
-            if (COMPILER_IS_GCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 8.0)
+            if (COMPILER_IS_GCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 8.0 AND NOT (${CMAKE_SYSTEM_PROCESSOR} MATCHES sparc.*))
                 add_compile_options(-fstack-clash-protection -fcf-protection)
             endif()
 
