$NetBSD: patch-cmake_benchmark.cmake,v 1.2 2020/01/03 08:21:36 adam Exp $

Find benchmark from pkgsrc.

--- cmake/benchmark.cmake.orig	2019-12-18 01:29:27.000000000 +0000
+++ cmake/benchmark.cmake
@@ -26,8 +26,12 @@ if(gRPC_BENCHMARK_PROVIDER STREQUAL "mod
     message(WARNING "gRPC_BENCHMARK_PROVIDER is \"module\" but BENCHMARK_ROOT_DIR is wrong")
   endif()
 elseif(gRPC_BENCHMARK_PROVIDER STREQUAL "package")
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
   endif()
