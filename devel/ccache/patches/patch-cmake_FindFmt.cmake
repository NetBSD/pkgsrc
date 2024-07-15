$NetBSD: patch-cmake_FindFmt.cmake,v 1.1 2024/07/15 15:06:42 adam Exp $

Find fmtlib 11.

--- cmake/FindFmt.cmake.orig	2024-07-15 09:38:26.402859261 +0000
+++ cmake/FindFmt.cmake
@@ -6,7 +6,7 @@ else()
   find_path(FMT_INCLUDE_DIR fmt/core.h)
   find_library(FMT_LIBRARY fmt)
   if(FMT_INCLUDE_DIR AND FMT_LIBRARY)
-    file(READ "${FMT_INCLUDE_DIR}/fmt/core.h" _fmt_core_h)
+    file(READ "${FMT_INCLUDE_DIR}/fmt/base.h" _fmt_core_h)
     string(REGEX MATCH "#define FMT_VERSION ([0-9]+)" _ "${_fmt_core_h}")
     math(EXPR _fmt_major "${CMAKE_MATCH_1} / 10000")
     math(EXPR _fmt_minor "${CMAKE_MATCH_1} / 100 % 100")
