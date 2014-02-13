$NetBSD: patch-cmake_dtrace.cmake,v 1.1 2014/02/13 14:38:08 jperkin Exp $

Build with newer DTrace.

--- cmake/dtrace.cmake.orig	2013-11-17 18:02:53.000000000 +0000
+++ cmake/dtrace.cmake
@@ -35,10 +35,11 @@ MACRO(CHECK_DTRACE)
  MARK_AS_ADVANCED(DTRACE)
 
  # On FreeBSD, dtrace does not handle userland tracing yet
- IF(DTRACE AND NOT CMAKE_SYSTEM_NAME MATCHES "FreeBSD"
-     AND NOT BUGGY_GCC_NO_DTRACE_MODULES)
-   SET(ENABLE_DTRACE ON CACHE BOOL "Enable dtrace")
+ IF(ENABLE_DTRACE AND (CMAKE_SYSTEM_NAME MATCHES "FreeBSD"
+    OR BUGGY_GCC_NO_DTRACE_MODULES OR NOT DTRACE))
+  MESSAGE(FATAL_ERROR "dtrace is not supported on this system")
  ENDIF()
+
  SET(HAVE_DTRACE ${ENABLE_DTRACE})
  IF(CMAKE_SYSTEM_NAME MATCHES "SunOS")
    IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
