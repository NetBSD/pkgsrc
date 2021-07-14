$NetBSD: patch-cmake_compilers_GNU.cmake,v 1.1 2021/07/14 17:56:52 adam Exp $

Do not link against dl.

--- cmake/compilers/GNU.cmake.orig	2021-07-14 13:06:07.988667592 +0000
+++ cmake/compilers/GNU.cmake
@@ -37,7 +37,6 @@ if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<AND:$<NOT:$<CXX_COMPILER_ID:Intel>>,$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},11.0>>>:-mwaitpkg>)
 endif()
 
-set(TBB_COMMON_LINK_LIBS dl)
 
 # Ignore -Werror set through add_compile_options() or added to CMAKE_CXX_FLAGS if TBB_STRICT is disabled.
 if (NOT TBB_STRICT AND COMMAND tbb_remove_compile_flag)
