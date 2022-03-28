$NetBSD: patch-cmake_PluginSetup.cmake,v 1.1 2022/03/28 19:32:38 bouyer Exp $

Make sure PKG_TARGET is defined

--- cmake/PluginSetup.cmake.orig	2022-03-28 12:35:19.226589920 +0200
+++ cmake/PluginSetup.cmake	2022-03-28 12:40:33.397145593 +0200
@@ -104,10 +104,6 @@
     set(PKG_TARGET_VERSION 16)
     set(QT_ANDROID ON)
 elseif(UNIX)
-    # Some linux dist:
-    execute_process(COMMAND "lsb_release" "-is" OUTPUT_VARIABLE PKG_TARGET)
-    execute_process(COMMAND "lsb_release" "-rs" OUTPUT_VARIABLE PKG_TARGET_VERSION)
-else()
     set(PKG_TARGET "unknown")
     set(PKG_TARGET_VERSION 1)
 endif()
