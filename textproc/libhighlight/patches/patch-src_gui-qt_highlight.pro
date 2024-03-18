$NetBSD: patch-src_gui-qt_highlight.pro,v 1.7 2024/03/18 18:56:40 schmonz Exp $

Restore non-.app macOS build settings from 3.59.

--- src/gui-qt/highlight.pro.orig	2024-03-15 14:46:32.000000000 +0000
+++ src/gui-qt/highlight.pro
@@ -89,8 +89,11 @@ macx-clang|macx-clang-arm64  {
     INCLUDEPATH += ../../include
     INCLUDEPATH+=/usr/local/Cellar/boost/1.84.0_1/include
 
-    QMAKE_MACOSX_DEPLOYMENT_TARGET=14.0
-    CONFIG += app_bundle
+    ###QMAKE_MACOSX_DEPLOYMENT_TARGET=14.0
+    ###CONFIG += app_bundle
+    QT_CONFIG -= no-pkg-config
+    CONFIG += link_pkgconfig
+    PKGCONFIG += lua
     LIBS += -L.. -lhighlight
     LIBS += -L/Users/andresimon/MyProjects/lua-5.4.1/src -llua
 
