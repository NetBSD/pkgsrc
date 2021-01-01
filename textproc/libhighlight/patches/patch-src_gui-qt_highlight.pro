$NetBSD: patch-src_gui-qt_highlight.pro,v 1.1 2021/01/01 19:41:37 schmonz Exp $

Restore non-.app macOS build settings from 3.59.

--- src/gui-qt/highlight.pro.orig	2020-12-21 10:56:19.000000000 +0000
+++ src/gui-qt/highlight.pro
@@ -80,8 +80,11 @@ macx-clang {
     INCLUDEPATH += ../../include
     INCLUDEPATH+=/usr/local/Cellar/boost/1.73.0/include
 
-    QMAKE_MACOSX_DEPLOYMENT_TARGET=10.13
-    CONFIG += app_bundle
+    ###QMAKE_MACOSX_DEPLOYMENT_TARGET=10.13
+    ###CONFIG += app_bundle
+    QT_CONFIG -= no-pkg-config
+    CONFIG += link_pkgconfig
+    PKGCONFIG += lua
     LIBS += -L.. -lhighlight
     LIBS += -L/Users/andresimon/MyProjects/lua-5.4.1/src -llua
 
