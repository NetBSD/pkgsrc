$NetBSD: patch-cmake_os_SunOS.cmake,v 1.3 2026/07/13 02:35:09 jnemeth Exp $

Disable a whole bunch of broken SunOS detection.

--- cmake/os/SunOS.cmake.orig	2026-04-07 15:27:15.000000000 +0000
+++ cmake/os/SunOS.cmake
@@ -26,6 +26,7 @@ INCLUDE(CheckCXXSourceCompiles)
 INCLUDE(CheckCSourceCompiles) 
 INCLUDE(CheckCXXSourceCompiles)
 
+IF(0)
 IF(CMAKE_SYSTEM_PROCESSOR MATCHES "sparc")
   SET(SOLARIS_SPARC 1)
 ELSE()
@@ -61,6 +62,7 @@ IF(NOT FORCE_UNSUPPORTED_COMPILER)
   ELSE()
     MESSAGE(FATAL_ERROR "Unsupported compiler!")
   ENDIF()
+ENDIF()
 ENDIF()
 
 # Enable 64 bit file offsets
