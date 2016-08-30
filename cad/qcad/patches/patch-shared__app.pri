$NetBSD: patch-shared__app.pri,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- shared_app.pri.orig	2016-07-01 07:13:14.000000000 +0000
+++ shared_app.pri
@@ -1,24 +1,24 @@
 include($$PWD/shared.pri)

 LIBS += \
-    -l$${RLIBNAME}ecmaapi \
-    -l$${RLIBNAME}gui \
-    -l$${RLIBNAME}entity \
-    -l$${RLIBNAME}operations \
-    -l$${RLIBNAME}spatialindex \
-    -lspatialindexnavel \
-    -l$${RLIBNAME}grid \
-    -l$${RLIBNAME}snap \
-    -l$${RLIBNAME}core \
-    -l$${RLIBNAME}stemmer \
-    -lstemmer \
-    -l$${RLIBNAME}zip \
-    -lquazip
+    -L$$PWD/src/scripting/ecmaapi -l$${RLIBNAME}ecmaapi \
+    -L$$PWD/src/gui -l$${RLIBNAME}gui \
+    -L$$PWD/src/entity -l$${RLIBNAME}entity \
+    -L$$PWD/src/operations -l$${RLIBNAME}operations \
+    -L$$PWD/src/spatialindex -l$${RLIBNAME}spatialindex \
+    -L$$PWD/src/3rdparty/spatialindexnavel -lspatialindexnavel \
+    -L$$PWD/src/grid -l$${RLIBNAME}grid \
+    -L$$PWD/src/snap -l$${RLIBNAME}snap \
+    -L$$PWD/src/core -l$${RLIBNAME}core \
+    -L$$PWD/src/stemmer -l$${RLIBNAME}stemmer \
+    -L$$PWD/src/3rdparty/stemmer -lstemmer \
+    -L$$PWD/src/zip -l$${RLIBNAME}zip \
+    -L$$PWD/src/3rdparty/quazip -lquazip

 !r_no_opennurbs {
     LIBS += \
-        -lopennurbs \
-        -lzlib
+        -L$$PWD/src/3rdparty/opennurbs/opennurbs -lopennurbs \
+        -L$$PWD/src/3rdparty/opennurbs/zlib -lzlib
 }

 win32 {
