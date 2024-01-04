$NetBSD: patch-src_spatialindex_spatialindex.pro,v 1.3 2024/01/04 21:50:29 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/spatialindex/spatialindex.pro.orig	2023-09-04 18:51:52.000000000 +0000
+++ src/spatialindex/spatialindex.pro
@@ -14,7 +14,9 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}spatialindex
-LIBS += -l$${RLIBNAME}core -lspatialindexnavel
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../3rdparty/legacy/spatialindexnavel -lspatialindexnavel
+INSTALLS += target
 OTHER_FILES += spatialindex.dox
 DEFINES += QCADSPATIALINDEX_LIBRARY
 RC_FILE = spatialindex.rc
