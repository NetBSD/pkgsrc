$NetBSD: patch-cmake_build__configurations_compiler__options.cmake,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- cmake/build_configurations/compiler_options.cmake.orig	2021-09-14 09:08:08.000000000 +0000
+++ cmake/build_configurations/compiler_options.cmake
@@ -69,7 +69,7 @@ IF(UNIX)  
     EXECUTE_PROCESS(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                     OUTPUT_VARIABLE GXX_VERSION)
     IF(GXX_VERSION VERSION_EQUAL 6.0 OR GXX_VERSION VERSION_GREATER 6.0)
-      STRING_PREPEND(COMMON_CXX_FLAGS "-std=gnu++03 ")
+      STRING_PREPEND(COMMON_CXX_FLAGS "-std=gnu++14 ")
     ENDIF()
     # Disable inline optimizations for valgrind testing to avoid false positives
     IF(WITH_VALGRIND)
@@ -104,7 +104,7 @@ IF(UNIX)  
     IF(CMAKE_CXX_COMPILER_VERSION VERSION_EQUAL 6.0 OR
         CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 6.0)
       IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
-        STRING_PREPEND(COMMON_CXX_FLAGS "-std=gnu++03 ")
+        STRING_PREPEND(COMMON_CXX_FLAGS "-std=gnu++14 ")
       ENDIF()
     ENDIF()
     IF(NOT DISABLE_SHARED)
