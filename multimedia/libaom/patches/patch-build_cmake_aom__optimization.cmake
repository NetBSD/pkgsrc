$NetBSD: patch-build_cmake_aom__optimization.cmake,v 1.5 2026/05/30 12:37:21 ryoon Exp $

* Use corrent help option for nasm-3.01.

--- cmake/aom_optimization.cmake.orig	2026-04-01 20:41:46.000000000 +0000
+++ cmake/aom_optimization.cmake
@@ -220,7 +220,7 @@ function(test_nasm)
       FATAL_ERROR "Unsupported nasm: multipass optimization not supported.")
   endif()
 
-  execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -hf
+  execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -h all
                   OUTPUT_VARIABLE nasm_helptext)
   if("${AOM_TARGET_CPU}" STREQUAL "x86")
     if("${AOM_TARGET_SYSTEM}" STREQUAL "Darwin")
