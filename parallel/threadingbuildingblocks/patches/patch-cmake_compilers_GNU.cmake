$NetBSD: patch-cmake_compilers_GNU.cmake,v 1.2 2021/07/29 20:03:28 fcambus Exp $

Only link against dl on Linux.

--- cmake/compilers/GNU.cmake.orig	2021-07-29 16:43:31.799016814 +0000
+++ cmake/compilers/GNU.cmake
@@ -37,7 +37,9 @@ if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<AND:$<NOT:$<CXX_COMPILER_ID:Intel>>,$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},11.0>>>:-mwaitpkg>)
 endif()
 
-set(TBB_COMMON_LINK_LIBS dl)
+if (CMAKE_SYSTEM_NAME MATCHES "Linux")
+    set(TBB_COMMON_LINK_LIBS dl)
+endif()
 
 # Ignore -Werror set through add_compile_options() or added to CMAKE_CXX_FLAGS if TBB_STRICT is disabled.
 if (NOT TBB_STRICT AND COMMAND tbb_remove_compile_flag)
