$NetBSD: patch-cmake_benchmark.cmake,v 1.1 2018/04/27 17:47:27 minskim Exp $

Find benchmark from pkgsrc.

--- cmake/benchmark.cmake.orig	2018-04-13 18:08:11.000000000 +0000
+++ cmake/benchmark.cmake
@@ -26,8 +26,12 @@ if("${gRPC_BENCHMARK_PROVIDER}" STREQUAL
       message(WARNING "gRPC_BENCHMARK_PROVIDER is \"module\" but BENCHMARK_ROOT_DIR is wrong")
   endif()
 elseif("${gRPC_BENCHMARK_PROVIDER}" STREQUAL "package")
-  # Use "CONFIG" as there is no built-in cmake module for benchmark.
-  find_package(benchmark REQUIRED CONFIG)
+  find_path(BENCHMARK_INCLUDE_DIR benchmark/benchmark.h)
+  find_library(BENCHMARK_LIB benchmark)
+  add_library(benchmark::benchmark UNKNOWN IMPORTED)
+  set_target_properties(benchmark::benchmark PROPERTIES
+    INTERFACE_INCLUDE_DIRECTORIES "${BENCHMARK_INCLUDE_DIR}"
+    IMPORTED_LOCATION "${BENCHMARK_LIB}")
   if(TARGET benchmark::benchmark)
     set(_gRPC_BENCHMARK_LIBRARIES benchmark::benchmark)
     # extract the include dir from target's properties
