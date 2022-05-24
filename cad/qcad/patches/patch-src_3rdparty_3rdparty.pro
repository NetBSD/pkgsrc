$NetBSD: patch-src_3rdparty_3rdparty.pro,v 1.2 2022/05/24 05:17:12 plunky Exp $

Support building with "unsupported" Qt versions. Sometimes the Qt version
in pkgsrc is later than the versions listed in QCAD source. Just use
v5.5.0 for all unknown Qt5 versions. Qt6 includes qtscriptgenerator

--- src/3rdparty/3rdparty.pro.orig	2022-05-15 09:24:30.635775811 +0100
+++ src/3rdparty/3rdparty.pro	2022-05-15 09:24:24.541676113 +0100
@@ -17,7 +17,7 @@
     }
     else {
         lessThan(QT_MAJOR_VERSION, 6) {
-            error("Script bindings not available for Qt version $${QT_VERSION}. You can add them to src/3rdparty/qt-labs-qtscriptgenerator-$${QT_VERSION} or use another version of Qt.")
+            SUBDIRS += qt-labs-qtscriptgenerator-5.5.0
         }
     }
 }
