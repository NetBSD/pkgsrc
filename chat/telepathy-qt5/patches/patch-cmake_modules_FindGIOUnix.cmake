$NetBSD: patch-cmake_modules_FindGIOUnix.cmake,v 1.1 2022/10/06 14:28:03 nros Exp $

* guniconnection.h is not in the gio-unix-2.0 dir anymore but in the glib-2.0 dir
  look for a file that is in gio-unix-2.0 in newer glib2

--- cmake/modules/FindGIOUnix.cmake.orig	2022-10-06 14:15:56.552617400 +0000
+++ cmake/modules/FindGIOUnix.cmake
@@ -19,7 +19,7 @@ include(UsePkgConfig)
 pkg_check_modules(PC_LibGIOUnix gio-unix-2.0)
 
 find_path(GIOUNIX_MAIN_INCLUDE_DIR
-          NAMES gio/gunixconnection.h
+          NAMES gio/gunixmounts.h
           HINTS ${PC_LibGIOUnix_INCLUDEDIR}
           PATH_SUFFIXES gio-unix-2.0)
 
