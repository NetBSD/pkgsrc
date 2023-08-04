$NetBSD: patch-src_configure.cmake,v 1.1 2023/08/04 19:16:47 adam Exp $

Support all UNIX platforms.

--- src/configure.cmake.orig	2023-07-07 12:29:08.000000000 +0000
+++ src/configure.cmake
@@ -10,7 +10,7 @@ set(INPUT_wayland_text_input_v4_wip OFF 
 
 #### Libraries
 
-if(LINUX OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(UNIX OR QT_FIND_ALL_PACKAGES_ALWAYS)
     # waylandclient libraries
     if(TARGET Wayland::Client)
         qt_internal_disable_find_package_global_promotion(Wayland::Client)
