$NetBSD: patch-Modules_FindGTK2.cmake,v 1.1 2019/01/04 17:47:12 triaxx Exp $

Test not enough robust. Open ticket on upstream:
https://gitlab.kitware.com/cmake/cmake/issues/17614

--- Modules/FindGTK2.cmake.orig	2018-12-13 11:57:40.000000000 +0000
+++ Modules/FindGTK2.cmake
@@ -762,7 +762,7 @@ foreach(_GTK2_component ${GTK2_FIND_COMP
         _GTK2_FIND_LIBRARY    (SIGC++ sigc true true)
         _GTK2_ADD_TARGET      (SIGC++)
         # Since sigc++ 2.5.1 c++11 support is required
-        if(GTK2_SIGC++CONFIG_INCLUDE_DIR)
+        if(GTK2_SIGC++_FOUND)
             _GTK2_SIGCXX_GET_VERSION(GTK2_SIGC++_VERSION_MAJOR
                                      GTK2_SIGC++_VERSION_MINOR
                                      GTK2_SIGC++_VERSION_MICRO
