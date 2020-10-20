$NetBSD: patch-cmake_compilerFlags.cmake,v 1.2 2020/10/20 07:07:24 tnn Exp $

Gcc on some platforms does not support -fcf-protection.

--- cmake/compilerFlags.cmake.orig	2020-06-30 13:33:22.000000000 +0000
+++ cmake/compilerFlags.cmake
@@ -25,7 +25,7 @@ if ( MINGW OR UNIX OR MSYS ) # MINGW, Li
 
         # This fails under Fedora, MinGW GCC 8.3.0 and CYGWIN/MSYS 9.3.0
         if (NOT (MINGW OR CMAKE_HOST_SOLARIS OR CYGWIN OR MSYS) )
-            if (COMPILER_IS_GCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 8.0)
+            if (COMPILER_IS_GCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 8.0 AND NOT (${CMAKE_SYSTEM_PROCESSOR} MATCHES "sparc.*|aarch64"))
                 add_compile_options(-fstack-clash-protection -fcf-protection)
             endif()
 
