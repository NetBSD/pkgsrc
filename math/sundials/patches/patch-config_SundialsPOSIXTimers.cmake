$NetBSD: patch-config_SundialsPOSIXTimers.cmake,v 1.1 2025/08/19 14:03:02 wiz Exp $

Fix build with cmake 4.

--- config/SundialsPOSIXTimers.cmake.orig	2025-08-19 14:00:46.204784736 +0000
+++ config/SundialsPOSIXTimers.cmake
@@ -43,7 +43,7 @@ if(SUNDIALS_POSIX_TIMERS)
 
     # Create a CMakeLists.txt file which will generate the test executable
     file(WRITE ${POSIXTest_DIR}/CMakeLists.txt
-      "CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2)\n"
+      "CMAKE_MINIMUM_REQUIRED(VERSION 3.5)\n"
       "PROJECT(posixtimerstest C)\n"
       "SET(CMAKE_VERBOSE_MAKEFILE ON)\n"
       "SET(CMAKE_C_COMPILER \"${CMAKE_C_COMPILER}\")\n"
