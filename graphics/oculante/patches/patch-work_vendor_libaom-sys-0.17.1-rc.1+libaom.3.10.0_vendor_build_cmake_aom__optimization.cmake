$NetBSD: patch-work_vendor_libaom-sys-0.17.1-rc.1+libaom.3.10.0_vendor_build_cmake_aom__optimization.cmake,v 1.1 2025/11/14 08:22:20 wiz Exp $

Fix build with nasm 3.0.

--- work/vendor/libaom-sys-0.17.1-rc.1+libaom.3.10.0/vendor/build/cmake/aom_optimization.cmake.orig	2006-07-24 01:21:28.000000000 +0000
+++ work/vendor/libaom-sys-0.17.1-rc.1+libaom.3.10.0/vendor/build/cmake/aom_optimization.cmake
@@ -212,7 +212,7 @@ endfunction()
 # Currently checks only for presence of required object formats and support for
 # the -Ox argument (multipass optimization).
 function(test_nasm)
-  execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -hf
+  execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -hO
                   OUTPUT_VARIABLE nasm_helptext)
 
   if(NOT "${nasm_helptext}" MATCHES "-Ox")
@@ -220,6 +220,9 @@ function(test_nasm)
       FATAL_ERROR "Unsupported nasm: multipass optimization not supported.")
   endif()
 
+  execute_process(COMMAND ${CMAKE_ASM_NASM_COMPILER} -hf
+                  OUTPUT_VARIABLE nasm_helptext)
+
   if("${AOM_TARGET_CPU}" STREQUAL "x86")
     if("${AOM_TARGET_SYSTEM}" STREQUAL "Darwin")
       if(NOT "${nasm_helptext}" MATCHES "macho32")
