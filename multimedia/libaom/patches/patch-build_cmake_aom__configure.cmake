$NetBSD: patch-build_cmake_aom__configure.cmake,v 1.2 2018/10/23 17:30:21 jperkin Exp $

Don't disable fortify just because it's a release build.
Set CPU correctly on SunOS.

--- build/cmake/aom_configure.cmake.orig	2018-10-01 03:20:05.000000000 +0000
+++ build/cmake/aom_configure.cmake
@@ -65,7 +65,11 @@ if(NOT AOM_TARGET_CPU)
     endif()
   elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "i386" OR
          "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86")
-    set(AOM_TARGET_CPU "x86")
+    if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
+      set(AOM_TARGET_CPU "x86")
+    elseif(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
+      set(AOM_TARGET_CPU "x86_64")
+    endif()
   elseif("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "^arm" OR
          "${CMAKE_SYSTEM_PROCESSOR}" MATCHES "^mips")
     set(AOM_TARGET_CPU "${CMAKE_SYSTEM_PROCESSOR}")
@@ -290,9 +294,6 @@ else()
     add_compiler_flag_if_supported("-Werror")
   endif()
 
-  if("${CMAKE_BUILD_TYPE}" MATCHES "Rel")
-    add_compiler_flag_if_supported("-U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0")
-  endif()
   add_compiler_flag_if_supported("-D_LARGEFILE_SOURCE")
   add_compiler_flag_if_supported("-D_FILE_OFFSET_BITS=64")
 endif()
