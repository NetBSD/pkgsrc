$NetBSD: patch-cmake_libfmt.cmake,v 1.1 2024/08/21 21:08:34 nia Exp $

Disable broken libfmt detection.

--- cmake/libfmt.cmake.orig	2024-05-03 09:45:28.584587681 +0000
+++ cmake/libfmt.cmake
@@ -25,28 +25,7 @@ MACRO(BUNDLE_LIBFMT)
 ENDMACRO()
 
 MACRO (CHECK_LIBFMT)
-  IF(WITH_LIBFMT STREQUAL "system" OR WITH_LIBFMT STREQUAL "auto")
-    SET(CMAKE_REQUIRED_INCLUDES ${LIBFMT_INCLUDE_DIR})
-    CHECK_CXX_SOURCE_RUNS(
-    "#define FMT_STATIC_THOUSANDS_SEPARATOR ','
-     #define FMT_HEADER_ONLY 1
-     #include <fmt/format-inl.h>
-     int main() {
-       int answer= 4321;
-       fmt::format_args::format_arg arg=
-         fmt::detail::make_arg<fmt::format_context>(answer);
-       return fmt::vformat(\"{:L}\", fmt::format_args(&arg, 1)).compare(\"4,321\");
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
