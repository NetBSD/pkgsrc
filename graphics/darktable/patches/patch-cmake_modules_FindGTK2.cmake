$NetBSD: patch-cmake_modules_FindGTK2.cmake,v 1.3 2011/11/20 01:16:23 dholland Exp $

Look for GTK in the right place.

Caution: this patch inserts a substitution of PREFIX that is expanded
from the pkgsrc makefile at pre-configure time. If regenerating this
patch, make sure to do it in a tree that hasn't been configured or
built to avoid permanently expanding the substitution.

--- cmake/modules/FindGTK2.cmake.orig	2011-08-24 09:20:29.000000000 +0000
+++ cmake/modules/FindGTK2.cmake
@@ -184,6 +184,9 @@ function(_GTK2_FIND_INCLUDE_DIR _var _hd
             /usr/openwin/lib
             /sw/include
             /sw/lib
+            @PREFIX@/include/glib
+            @PREFIX@/include
+            @PREFIX@/lib
             $ENV{GTKMM_BASEPATH}/include
             $ENV{GTKMM_BASEPATH}/lib
             [HKEY_CURRENT_USER\\SOFTWARE\\gtkmm\\2.4;Path]/include
