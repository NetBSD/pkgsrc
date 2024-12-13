$NetBSD: patch-cmake_libfmt.cmake,v 1.3 2024/12/13 14:07:45 nia Exp $

Disable broken libfmt detection.

--- cmake/libfmt.cmake.orig	2024-12-13 13:59:17.741050173 +0000
+++ cmake/libfmt.cmake
@@ -25,29 +25,7 @@ MACRO(BUNDLE_LIBFMT)
 ENDMACRO()
 
 MACRO (CHECK_LIBFMT)
-  IF(WITH_LIBFMT STREQUAL "system" OR WITH_LIBFMT STREQUAL "auto")
-    SET(CMAKE_REQUIRED_INCLUDES ${LIBFMT_INCLUDE_DIR})
-    CHECK_CXX_SOURCE_RUNS(
-    "#define FMT_STATIC_THOUSANDS_SEPARATOR ','
-     #define FMT_HEADER_ONLY 1
-     #include <fmt/args.h>
-     int main() {
-       using ArgStore= fmt::dynamic_format_arg_store<fmt::format_context>;
-       ArgStore arg_store;
-       int answer= 4321;
-       arg_store.push_back(answer);
-       return fmt::vformat(\"{:L}\", arg_store).compare(\"4,321\");
-     }" HAVE_SYSTEM_LIBFMT)
-    SET(CMAKE_REQUIRED_INCLUDES)
-  ENDIF()
-  IF(NOT HAVE_SYSTEM_LIBFMT OR WITH_LIBFMT STREQUAL "bundled")
-    IF (WITH_LIBFMT STREQUAL "system")
-      MESSAGE(FATAL_ERROR "system libfmt library is not found or unusable")
-    ENDIF()
-    BUNDLE_LIBFMT()
-  ELSE()
-    FIND_FILE(Libfmt_core_h fmt/core.h) # for build_depends.cmake
-  ENDIF()
+  FIND_FILE(Libfmt_core_h fmt/core.h) # for build_depends.cmake
 ENDMACRO()
 
 MARK_AS_ADVANCED(LIBFMT_INCLUDE_DIR)
