$NetBSD: patch-src_gui-qt_highlight.pro,v 1.3 2022/10/03 18:09:12 schmonz Exp $

Restore non-.app macOS build settings from 3.59.

--- src/gui-qt/highlight.pro.orig	2022-09-28 17:52:30.000000000 +0000
+++ src/gui-qt/highlight.pro
@@ -80,8 +80,11 @@ macx-clang {
     INCLUDEPATH += ../../include
     INCLUDEPATH+=/usr/local/Cellar/boost/1.78.0_1/include
 
-    QMAKE_MACOSX_DEPLOYMENT_TARGET=10.13
-    CONFIG += app_bundle
+    ###QMAKE_MACOSX_DEPLOYMENT_TARGET=10.13
+    ###CONFIG += app_bundle
+    QT_CONFIG -= no-pkg-config
+    CONFIG += link_pkgconfig
+    PKGCONFIG += lua
     LIBS += -L.. -lhighlight
     LIBS += -L/Users/andresimon/MyProjects/lua-5.4.1/src -llua
 
