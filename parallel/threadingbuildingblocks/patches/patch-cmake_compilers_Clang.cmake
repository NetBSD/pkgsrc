$NetBSD: patch-cmake_compilers_Clang.cmake,v 1.2 2021/07/29 20:03:28 fcambus Exp $

Only link against dl on Linux.

--- cmake/compilers/Clang.cmake.orig	2021-07-29 16:43:27.979066736 +0000
+++ cmake/compilers/Clang.cmake
@@ -42,7 +42,9 @@ if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},12.0>>:-mwaitpkg>)
 endif()
 
-set(TBB_COMMON_LINK_LIBS dl)
+if (CMAKE_SYSTEM_NAME MATCHES "Linux")
+    set(TBB_COMMON_LINK_LIBS dl)
+endif()
 
 if (ANDROID_PLATFORM)
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} $<$<NOT:$<CONFIG:Debug>>:-D_FORTIFY_SOURCE=2>)
