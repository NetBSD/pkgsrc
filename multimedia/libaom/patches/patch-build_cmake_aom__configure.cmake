$NetBSD: patch-build_cmake_aom__configure.cmake,v 1.4 2021/10/09 14:47:24 nia Exp $

- Don't disable fortify just because it's a release build.
- Set CPU correctly on SunOS.
- Add support for NetBSD/*arm*

--- build/cmake/aom_configure.cmake.orig	2021-10-09 07:54:04.000000000 +0000
+++ build/cmake/aom_configure.cmake
@@ -66,12 +66,16 @@ if(NOT AOM_TARGET_CPU)
                     "      CMAKE_GENERATOR=${CMAKE_GENERATOR}\n")
     endif()
   elseif(cpu_lowercase STREQUAL "i386" OR cpu_lowercase STREQUAL "x86")
-    set(AOM_TARGET_CPU "x86")
-  elseif(cpu_lowercase MATCHES "^arm" OR cpu_lowercase MATCHES "^mips")
+    if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
+      set(AOM_TARGET_CPU "x86")
+    elseif(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
+      set(AOM_TARGET_CPU "x86_64")
+    endif()
+  elseif(cpu_lowercase MATCHES "^(arm|earm)" OR cpu_lowercase MATCHES "^mips")
     set(AOM_TARGET_CPU "${cpu_lowercase}")
   elseif(cpu_lowercase MATCHES "aarch64")
     set(AOM_TARGET_CPU "arm64")
-  elseif(cpu_lowercase MATCHES "^ppc")
+  elseif(cpu_lowercase MATCHES "^(ppc|powerpc)")
     set(AOM_TARGET_CPU "ppc")
   else()
     message(WARNING "The architecture ${CMAKE_SYSTEM_PROCESSOR} is not "
@@ -321,9 +325,6 @@ else()
     add_compiler_flag_if_supported("-Werror")
   endif()
 
-  if(build_type_lowercase MATCHES "rel")
-    add_compiler_flag_if_supported("-U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0")
-  endif()
   add_compiler_flag_if_supported("-D_LARGEFILE_SOURCE")
   add_compiler_flag_if_supported("-D_FILE_OFFSET_BITS=64")
 endif()
