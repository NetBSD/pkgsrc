$NetBSD: patch-src_3rdparty_3rdparty.pro,v 1.4 2024/01/04 21:50:29 plunky Exp $

Support building with "unsupported" Qt versions. Sometimes the Qt version
in pkgsrc is later than the versions listed in QCAD source. Just use
v5.5.0 for all unknown Qt5 versions. Qt6 includes qtscriptgenerator

--- src/3rdparty/3rdparty.pro.orig	2023-09-04 18:51:52.000000000 +0000
+++ src/3rdparty/3rdparty.pro
@@ -1,7 +1,6 @@
 include (../../shared.pri)
 TEMPLATE = subdirs
 SUBDIRS = \
-    stemmer
 
 contains(QMAKE_COMPILER_DEFINES, _MSC_VER=1929) {
     # MSVC 2019
@@ -24,7 +23,7 @@ else {
     }
     else {
         lessThan(QT_MAJOR_VERSION, 6) {
-            error("Script bindings not available for Qt version $${QT_VERSION}. You can add them to src/3rdparty/qt-labs-qtscriptgenerator-$${QT_VERSION} or use another version of Qt.")
+            SUBDIRS += qt-labs-qtscriptgenerator-5.5.0
         }
     }
 }
