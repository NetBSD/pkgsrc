$NetBSD: patch-cmake_dtrace.cmake,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

Build with newer DTrace.

--- cmake/dtrace.cmake.orig	2014-10-09 13:46:25.000000000 +0000
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
