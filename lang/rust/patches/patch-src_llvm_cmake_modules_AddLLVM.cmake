$NetBSD: patch-src_llvm_cmake_modules_AddLLVM.cmake,v 1.2 2018/09/14 10:04:43 jperkin Exp $

"-z discard-unused" is only supported by Oracle Solaris ld.

--- src/llvm/cmake/modules/AddLLVM.cmake.orig	2018-08-01 16:32:37.000000000 +0000
+++ src/llvm/cmake/modules/AddLLVM.cmake
@@ -219,8 +219,6 @@ function(add_link_opts target_name)
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
       elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD AND NOT ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD")
         # Object files are compiled with -ffunction-data-sections.
         # Versions of bfd ld < 2.23.1 have a bug in --gc-sections that breaks
