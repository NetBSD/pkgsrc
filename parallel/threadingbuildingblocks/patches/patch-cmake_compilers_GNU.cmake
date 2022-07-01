$NetBSD: patch-cmake_compilers_GNU.cmake,v 1.4 2022/07/01 22:38:25 adam Exp $

Automatically choose dl library.

--- cmake/compilers/GNU.cmake.orig	2021-12-17 13:40:54.000000000 +0000
+++ cmake/compilers/GNU.cmake
@@ -41,7 +41,7 @@ if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86
 endif()
 
 if (NOT MINGW)
-    set(TBB_COMMON_LINK_LIBS dl)
+    set(TBB_COMMON_LINK_LIBS ${CMAKE_DL_LIBS})
 endif()
 
 # Ignore -Werror set through add_compile_options() or added to CMAKE_CXX_FLAGS if TBB_STRICT is disabled.
