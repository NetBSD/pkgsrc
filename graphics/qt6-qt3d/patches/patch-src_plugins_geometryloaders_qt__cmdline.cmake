$NetBSD: patch-src_plugins_geometryloaders_qt__cmdline.cmake,v 1.1 2022/11/25 22:19:12 nros Exp $

* add missing configure options so that they can be set explicitly

--- src/plugins/geometryloaders/qt_cmdline.cmake.orig	2022-11-25 21:44:20.224057218 +0000
+++ src/plugins/geometryloaders/qt_cmdline.cmake
@@ -0,0 +1 @@
+qt_commandline_option(fbxsdk TYPE enum VALUES no system)
