$NetBSD: patch-cmake_build__configurations_compiler__options.cmake,v 1.1 2021/04/29 16:50:32 adam Exp $

Require C++14.

--- cmake/build_configurations/compiler_options.cmake.orig	2021-04-29 13:13:28.501383898 +0000
+++ cmake/build_configurations/compiler_options.cmake
@@ -73,7 +73,7 @@ IF(UNIX)  
     EXECUTE_PROCESS(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                     OUTPUT_VARIABLE GXX_VERSION)
     IF(GXX_VERSION VERSION_EQUAL 6.0 OR GXX_VERSION VERSION_GREATER 6.0)
-      STRING_PREPEND(COMMON_CXX_FLAGS "-std=gnu++03 ")
+      STRING_PREPEND(COMMON_CXX_FLAGS "-std=gnu++14 ")
     ENDIF()
     # Disable inline optimizations for valgrind testing to avoid false positives
     IF(WITH_VALGRIND)
@@ -112,7 +112,7 @@ IF(UNIX)  
     IF(CMAKE_CXX_COMPILER_VERSION VERSION_EQUAL 6.0 OR
         CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 6.0)
       IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
-        STRING_PREPEND(COMMON_CXX_FLAGS "-std=gnu++03 ")
+        STRING_PREPEND(COMMON_CXX_FLAGS "-std=gnu++14 ")
       ENDIF()
     ENDIF()
     IF(NOT DISABLE_SHARED)
