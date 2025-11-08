$NetBSD: patch-build_cmake_aom__optimization.cmake,v 1.3 2025/11/08 02:16:58 ryoon Exp $

* Use corrent help option for nasm-3.01.

--- build/cmake/aom_optimization.cmake.orig	2025-11-08 02:08:28.608211708 +0000
+++ build/cmake/aom_optimization.cmake
@@ -212,7 +212,7 @@ endfunction()
 # Currently checks only for presence of required object formats and support for
 # the -Ox argument (multipass optimization).
 function(test_nasm)
-  execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -hf
+  execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -h all
                   OUTPUT_VARIABLE nasm_helptext)
 
   if(NOT "${nasm_helptext}" MATCHES "-Ox")
