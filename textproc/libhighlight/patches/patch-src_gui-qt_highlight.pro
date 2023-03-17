$NetBSD: patch-src_gui-qt_highlight.pro,v 1.4 2023/03/17 11:49:50 schmonz Exp $

Restore non-.app macOS build settings from 3.59.

--- src/gui-qt/highlight.pro.orig	2023-03-14 14:17:30.000000000 +0000
+++ src/gui-qt/highlight.pro
@@ -81,8 +81,11 @@ macx-clang|macx-clang-arm64  {
     INCLUDEPATH += ../../include
     INCLUDEPATH+=/usr/local/Cellar/boost/1.81.0_1/include
 
-    QMAKE_MACOSX_DEPLOYMENT_TARGET=12.3
-    CONFIG += app_bundle
+    ###QMAKE_MACOSX_DEPLOYMENT_TARGET=12.3
+    ###CONFIG += app_bundle
+    QT_CONFIG -= no-pkg-config
+    CONFIG += link_pkgconfig
+    PKGCONFIG += lua
     LIBS += -L.. -lhighlight
     LIBS += -L/Users/andresimon/MyProjects/lua-5.4.1/src -llua
 
