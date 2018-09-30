$NetBSD: patch-build_cmake_aom__optimization.cmake,v 1.1 2018/09/30 18:58:16 maya Exp $

Assume everyone besides Darwin/Windows uses ELF.

--- build/cmake/aom_optimization.cmake.orig	2018-09-28 20:57:38.000000000 +0000
+++ build/cmake/aom_optimization.cmake
@@ -83,24 +83,20 @@ function(get_asm_obj_format out_format)
   if("${AOM_TARGET_CPU}" STREQUAL "x86_64")
     if("${AOM_TARGET_SYSTEM}" STREQUAL "Darwin")
       set(objformat "macho64")
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
-      set(objformat "elf64")
     elseif("${AOM_TARGET_SYSTEM}" STREQUAL "MSYS" OR "${AOM_TARGET_SYSTEM}"
            STREQUAL "Windows")
       set(objformat "win64")
     else()
-      message(FATAL_ERROR "Unknown obj format: ${AOM_TARGET_SYSTEM}")
+      set(objformat "elf64")
     endif()
   elseif("${AOM_TARGET_CPU}" STREQUAL "x86")
     if("${AOM_TARGET_SYSTEM}" STREQUAL "Darwin")
       set(objformat "macho32")
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
-      set(objformat "elf32")
     elseif("${AOM_TARGET_SYSTEM}" STREQUAL "MSYS" OR "${AOM_TARGET_SYSTEM}"
            STREQUAL "Windows")
       set(objformat "win32")
     else()
-      message(FATAL_ERROR "Unknown obj format: ${AOM_TARGET_SYSTEM}")
+      set(objformat "elf32")
     endif()
   else()
     message(FATAL_ERROR
@@ -171,7 +167,7 @@ function(test_nasm)
         message(FATAL_ERROR
                   "Unsupported nasm: macho32 object format not supported.")
       endif()
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
+    else()
       if(NOT "${nasm_helptext}" MATCHES "elf32")
         message(FATAL_ERROR
                   "Unsupported nasm: elf32 object format not supported.")
@@ -183,7 +179,7 @@ function(test_nasm)
         message(FATAL_ERROR
                   "Unsupported nasm: macho64 object format not supported.")
       endif()
-    elseif("${AOM_TARGET_SYSTEM}" STREQUAL "Linux")
+    else()
       if(NOT "${nasm_helptext}" MATCHES "elf64")
         message(FATAL_ERROR
                   "Unsupported nasm: elf64 object format not supported.")
