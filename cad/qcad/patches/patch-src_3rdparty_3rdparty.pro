$NetBSD: patch-src_3rdparty_3rdparty.pro,v 1.3 2023/03/25 13:16:11 wiz Exp $

Support building with "unsupported" Qt versions. Sometimes the Qt version
in pkgsrc is later than the versions listed in QCAD source. Just use
v5.5.0 for all unknown Qt5 versions. Qt6 includes qtscriptgenerator

--- src/3rdparty/3rdparty.pro.orig	2022-05-17 09:39:30.000000000 +0000
+++ src/3rdparty/3rdparty.pro
@@ -2,7 +2,6 @@ include (../../shared.pri)
 TEMPLATE = subdirs
 SUBDIRS = \
     spatialindexnavel \
-    stemmer
 
 !r_no_opennurbs {
     SUBDIRS += opennurbs
@@ -17,7 +16,7 @@ SUBDIRS = \
     }
     else {
         lessThan(QT_MAJOR_VERSION, 6) {
-            error("Script bindings not available for Qt version $${QT_VERSION}. You can add them to src/3rdparty/qt-labs-qtscriptgenerator-$${QT_VERSION} or use another version of Qt.")
+            SUBDIRS += qt-labs-qtscriptgenerator-5.5.0
         }
     }
 }
