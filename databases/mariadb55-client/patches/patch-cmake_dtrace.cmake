$NetBSD: patch-cmake_dtrace.cmake,v 1.1 2015/05/07 12:45:29 fhajny Exp $

Build with newer DTrace.

--- cmake/dtrace.cmake.orig	2014-05-10 22:36:23.000000000 +0000
+++ cmake/dtrace.cmake
@@ -40,10 +40,10 @@ MACRO(CHECK_DTRACE)
  ENDIF()
 
  # On FreeBSD, dtrace does not handle userland tracing yet
- IF(DTRACE AND NOT CMAKE_SYSTEM_NAME MATCHES "FreeBSD"
-     AND NOT BUGGY_GCC_NO_DTRACE_MODULES
-     AND NOT BUGGY_LINUX_DTRACE) 
-   SET(ENABLE_DTRACE ON CACHE BOOL "Enable dtrace")
+ IF(ENABLE_DTRACE AND (CMAKE_SYSTEM_NAME MATCHES "FreeBSD"
+    OR BUGGY_GCC_NO_DTRACE_MODULES
+    OR BUGGY_LINUX_DTRACE OR NOT DTRACE))
+  MESSAGE(FATAL_ERROR "dtrace is not supported on this system")
  ENDIF()
  SET(HAVE_DTRACE ${ENABLE_DTRACE})
  IF(CMAKE_SYSTEM_NAME MATCHES "SunOS")
