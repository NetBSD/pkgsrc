$NetBSD: patch-src_spatialindex_spatialindex.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/spatialindex/spatialindex.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/spatialindex/spatialindex.pro
@@ -14,8 +14,8 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}spatialindex
-LIBS += -l$${RLIBNAME}core -lspatialindexnavel
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../3rdparty/spatialindexnavel -lspatialindexnavel
+INSTALLS += target
 OTHER_FILES += spatialindex.dox
 DEFINES += QCADSPATIALINDEX_LIBRARY
-
-#POST_TARGETDEPS += ../../$$ROUTDIR/$${RLIBPRE}spatialindexnavel$${RLIBPOSTDLL}
