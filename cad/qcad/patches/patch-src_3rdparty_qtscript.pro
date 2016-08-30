$NetBSD: patch-src_3rdparty_qtscript.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

create a fake qmake file, so that we can create Makefiles for
the specific QT_VERSION subdirectory with different options

--- src/3rdparty/qtscript.pro.orig	2016-08-02 08:36:34.720522859 +0000
+++ src/3rdparty/qtscript.pro
@@ -0,0 +1,8 @@
+include (../../shared.pri)
+TEMPLATE = subdirs
+
+!r_mobile {
+    exists(qt-labs-qtscriptgenerator-$${QT_VERSION}) {
+        SUBDIRS += qt-labs-qtscriptgenerator-$${QT_VERSION}
+    }
+}
