$NetBSD: patch-build_cmake_aom__configure.cmake,v 1.10 2026/08/30 15:37:38 ryoon Exp $

- Don't disable fortify just because it's a release build.
- Set CPU correctly on SunOS.
- Add support for NetBSD/*arm*

--- cmake/aom_configure.cmake.orig	2026-08-25 18:18:29.000000000 +0000
+++ cmake/aom_configure.cmake
@@ -70,11 +70,16 @@ if(NOT AOM_TARGET_CPU)
     endif()
   elseif(cpu_lowercase STREQUAL "i386" OR cpu_lowercase STREQUAL "x86")
     set(AOM_TARGET_CPU "x86")
-  elseif(cpu_lowercase MATCHES "^arm")
+    if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
+      set(AOM_TARGET_CPU "x86")
+    elseif(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
+      set(AOM_TARGET_CPU "x86_64")
+    endif()
+  elseif(cpu_lowercase MATCHES "^(arm|earm)")
     set(AOM_TARGET_CPU "${cpu_lowercase}")
   elseif(cpu_lowercase MATCHES "aarch64")
     set(AOM_TARGET_CPU "arm64")
-  elseif(cpu_lowercase MATCHES "^ppc")
+  elseif(cpu_lowercase MATCHES "^(ppc|powerpc)")
     set(AOM_TARGET_CPU "ppc")
   elseif(cpu_lowercase MATCHES "^riscv")
     set(AOM_TARGET_CPU "riscv")
