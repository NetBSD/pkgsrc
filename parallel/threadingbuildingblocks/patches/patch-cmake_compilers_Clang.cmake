$NetBSD: patch-cmake_compilers_Clang.cmake,v 1.1 2021/07/14 17:56:52 adam Exp $

Do not link against dl.

--- cmake/compilers/Clang.cmake.orig	2021-07-14 13:02:23.067505600 +0000
+++ cmake/compilers/Clang.cmake
@@ -42,7 +42,6 @@ if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},12.0>>:-mwaitpkg>)
 endif()
 
-set(TBB_COMMON_LINK_LIBS dl)
 
 if (ANDROID_PLATFORM)
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} $<$<NOT:$<CONFIG:Debug>>:-D_FORTIFY_SOURCE=2>)
