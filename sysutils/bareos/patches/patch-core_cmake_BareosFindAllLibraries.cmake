$NetBSD: patch-core_cmake_BareosFindAllLibraries.cmake,v 1.1 2020/07/28 06:36:29 kardel Exp $

provide a way to disable googletest which may be found by
cmake but it is not in buildlink. can be optionalized
later.

--- core/cmake/BareosFindAllLibraries.cmake.orig	2020-06-23 13:14:52.254196443 +0000
+++ core/cmake/BareosFindAllLibraries.cmake
@@ -82,7 +82,7 @@ bareosfindlibrary("util")
 bareosfindlibrary("dl")
 bareosfindlibrary("acl")
 # BareosFindLibrary("wrap")
-if (NOT ${CMAKE_CXX_COMPILER_ID} MATCHES SunPro)
+if (NOT ${CMAKE_CXX_COMPILER_ID} MATCHES SunPro AND NOT SKIP_GTEST)
   bareosfindlibrary("gtest")
   bareosfindlibrary("gtest_main")
   bareosfindlibrary("gmock")
