$NetBSD: patch-cmake_dependencies.cmake,v 1.1 2025/10/16 15:01:52 adam Exp $

Don't look for boost_system library.

--- cmake/dependencies.cmake.orig	2025-10-16 14:51:38.028310288 +0000
+++ cmake/dependencies.cmake
@@ -7,7 +7,6 @@ find_package(Boost COMPONENTS
   filesystem
   iostreams
   regex
-  system
   thread
   REQUIRED
 )
