$NetBSD: patch-external_llvm-project_openmp_runtime_cmake_LibompCheckLinkerFlag.cmake,v 1.1 2025/08/21 16:36:52 ryoon Exp $

--- external/llvm-project/openmp/runtime/cmake/LibompCheckLinkerFlag.cmake.orig	2025-08-21 15:43:11.406533197 +0000
+++ external/llvm-project/openmp/runtime/cmake/LibompCheckLinkerFlag.cmake
@@ -18,7 +18,7 @@ function(libomp_check_linker_flag flag b
   set(library_source
     "int foo(int a) { return a*a; }")
   set(cmake_source
-    "cmake_minimum_required(VERSION 2.8)
+    "cmake_minimum_required(VERSION 3.5)
      project(foo C)
      set(CMAKE_SHARED_LINKER_FLAGS \"${flag}\")
      add_library(foo SHARED src_to_link.c)")
