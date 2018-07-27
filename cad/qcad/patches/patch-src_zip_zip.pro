$NetBSD: patch-src_zip_zip.pro,v 1.2 2018/07/27 14:12:41 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/zip/zip.pro.orig	2017-12-19 14:26:30.000000000 +0000
+++ src/zip/zip.pro
@@ -23,7 +23,9 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}zip
-LIBS += -l$${RLIBNAME}core -lquazip
+INSTALLS += target
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../3rdparty/quazip -lquazip
 OTHER_FILES += zip.dox
 DEFINES += QCADZIP_LIBRARY
 RC_FILE = zip.rc
