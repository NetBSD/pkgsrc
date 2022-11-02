$NetBSD: patch-cmake_os_SunOS.cmake,v 1.2 2022/11/02 17:02:10 jperkin Exp $

Disable a whole bunch of broken SunOS detection.

--- cmake/os/SunOS.cmake.orig	2022-09-13 16:15:16.000000000 +0000
+++ cmake/os/SunOS.cmake
@@ -25,6 +25,7 @@ INCLUDE(CheckCSourceRuns)
 INCLUDE(CheckCSourceCompiles) 
 INCLUDE(CheckCXXSourceCompiles)
 
+IF(0)
 IF(CMAKE_SYSTEM_PROCESSOR MATCHES "sparc")
   SET(SOLARIS_SPARC 1)
 ELSE()
@@ -60,6 +61,7 @@ IF(NOT FORCE_UNSUPPORTED_COMPILER)
     MESSAGE(FATAL_ERROR "Unsupported compiler!")
   ENDIF()
 ENDIF()
+ENDIF()
 
 # Enable 64 bit file offsets
 ADD_DEFINITIONS(-D_FILE_OFFSET_BITS=64)
