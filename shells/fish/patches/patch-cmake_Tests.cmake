$NetBSD: patch-cmake_Tests.cmake,v 1.1 2025/08/18 07:38:27 wiz Exp $

Fix build with cmake 4.

--- cmake/Tests.cmake.orig	2025-08-18 07:37:21.924160132 +0000
+++ cmake/Tests.cmake
@@ -41,15 +41,6 @@ add_custom_target(fish_run_tests
   USES_TERMINAL
 )
 
-# If CMP0037 is available, also make an alias "test" target.
-# Note that this policy may not be available, in which case definining such a target silently fails.
-cmake_policy(PUSH)
-if(POLICY CMP0037)
-  cmake_policy(SET CMP0037 OLD)
-  add_custom_target(test DEPENDS fish_run_tests)
-endif()
-cmake_policy(POP)
-
 # Build the low-level tests code
 add_executable(fish_tests EXCLUDE_FROM_ALL
                src/fish_tests.cpp)
