$NetBSD: patch-src_entity_entity.pro,v 1.2 2018/07/27 14:12:41 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/entity/entity.pro.orig	2017-12-19 14:26:30.000000000 +0000
+++ src/entity/entity.pro
@@ -117,10 +117,12 @@ else {
 }
 NAME = $${RLIBNAME}entity
 TARGET = $${NAME}
+INSTALLS += target
 OTHER_FILES += entity.dox
 DEFINES += QCADENTITY_LIBRARY
 RC_FILE = entity.rc
-LIBS += -l$${RLIBNAME}core -lopennurbs
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../3rdparty/opennurbs/opennurbs -lopennurbs
 !win32 {
     include( ../../shared_ts.pri )
 }
