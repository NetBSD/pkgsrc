$NetBSD: patch-shared__app.pri,v 1.4 2022/05/24 05:17:12 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- shared_app.pri.orig	2022-03-25 09:42:54.000000000 +0000
+++ shared_app.pri
@@ -1,25 +1,24 @@
 include($$PWD/shared.pri)
 
 lessThan(QT_MAJOR_VERSION, 6) {
-    LIBS += -l$${RLIBNAME}ecmaapi
+    LIBS += -L$$PWD/src/scripting/ecmaapi -l$${RLIBNAME}ecmaapi
 }
 
 LIBS += \
-    -l$${RLIBNAME}gui \
-    -l$${RLIBNAME}entity \
-    -l$${RLIBNAME}operations \
-    -l$${RLIBNAME}spatialindex \
-    -lspatialindexnavel \
-    -l$${RLIBNAME}grid \
-    -l$${RLIBNAME}snap \
-    -l$${RLIBNAME}core \
-    -l$${RLIBNAME}stemmer \
-    -lstemmer
+    -L$$PWD/src/gui -l$${RLIBNAME}gui \
+    -L$$PWD/src/entity -l$${RLIBNAME}entity \
+    -L$$PWD/src/operations -l$${RLIBNAME}operations \
+    -L$$PWD/src/spatialindex -l$${RLIBNAME}spatialindex \
+    -L$$PWD/src/3rdparty/spatialindexnavel -lspatialindexnavel \
+    -L$$PWD/src/grid -l$${RLIBNAME}grid \
+    -L$$PWD/src/snap -l$${RLIBNAME}snap \
+    -L$$PWD/src/core -l$${RLIBNAME}core \
+    -L$$PWD/src/stemmer -l$${RLIBNAME}stemmer \
+    -L$$PWD/src/3rdparty/stemmer -lstemmer
 
 !r_no_opennurbs {
     LIBS += \
-        -lopennurbs \
-        -lzlib
+        -L$$PWD/src/3rdparty/opennurbs/opennurbs -lopennurbs
 }
 
 win32 {
