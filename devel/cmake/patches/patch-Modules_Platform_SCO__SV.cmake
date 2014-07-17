$NetBSD: patch-Modules_Platform_SCO__SV.cmake,v 1.1 2014/07/17 13:44:28 ryoon Exp $

* so filename versioning requires CMAKE_SHARED_LIBRARY_SONAME_C_FLAG.

--- Modules/Platform/SCO_SV.cmake.orig	2014-01-16 17:15:08.000000000 +0000
+++ Modules/Platform/SCO_SV.cmake
@@ -1,2 +1,3 @@
 set(CMAKE_DL_LIBS "")
+set(CMAKE_SHARED_LIBRARY_SONAME_C_FLAG "-h,")
 include(Platform/UnixPaths)
