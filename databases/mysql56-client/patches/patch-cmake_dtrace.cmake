$NetBSD: patch-cmake_dtrace.cmake,v 1.2 2014/08/10 15:11:57 adam Exp $

Build with newer DTrace.

--- cmake/dtrace.cmake.orig	2014-07-18 15:48:39.000000000 +0000
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
  EXECUTE_PROCESS(
    COMMAND ${DTRACE} -V
