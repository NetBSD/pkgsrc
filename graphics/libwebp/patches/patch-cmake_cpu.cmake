$NetBSD: patch-cmake_cpu.cmake,v 1.1 2026/07/02 14:15:58 ryoon Exp $

* Second webp_check_compiler_flag() does not detect compiler capability.
  Fix build wth GCC 10.5.0 under NetBSD 10.

--- cmake/cpu.cmake.orig	2026-07-02 14:11:26.838482654 +0000
+++ cmake/cpu.cmake
@@ -94,7 +94,7 @@ foreach(I_SIMD RANGE ${WEBP_SIMD_FLAGS_RANGE})
       set(SIMD_COMPILE_FLAG "-msimd128 ${SIMD_COMPILE_FLAG}")
     endif()
     set(CMAKE_REQUIRED_FLAGS ${SIMD_COMPILE_FLAG})
-    webp_check_compiler_flag(${WEBP_SIMD_FLAG} ${WEBP_ENABLE_SIMD})
+    #webp_check_compiler_flag(${WEBP_SIMD_FLAG} ${WEBP_ENABLE_SIMD})
   else()
     if(MSVC AND SIMD_ENABLE_FLAGS)
       # The detection for SSE2/SSE4 support under MSVC is based on the compiler
