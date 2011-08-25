$NetBSD: patch-cmake_modules_FindGTK2.cmake,v 1.2 2011/08/25 14:42:53 jakllsch Exp $

Look for GTK where we might find it.  Should honor ${PREFIX} someday.

--- cmake/modules/FindGTK2.cmake.orig	2011-08-24 09:20:29.000000000 +0000
+++ cmake/modules/FindGTK2.cmake
@@ -184,6 +184,9 @@ function(_GTK2_FIND_INCLUDE_DIR _var _hd
             /usr/openwin/lib
             /sw/include
             /sw/lib
+            /usr/pkg/include/glib
+            /usr/pkg/include
+            /usr/pkg/lib
             $ENV{GTKMM_BASEPATH}/include
             $ENV{GTKMM_BASEPATH}/lib
             [HKEY_CURRENT_USER\\SOFTWARE\\gtkmm\\2.4;Path]/include
