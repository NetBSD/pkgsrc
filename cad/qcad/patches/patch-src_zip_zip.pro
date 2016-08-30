$NetBSD: patch-src_zip_zip.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/zip/zip.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/zip/zip.pro
@@ -23,8 +23,8 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}zip
-LIBS += -l$${RLIBNAME}core -lquazip
+INSTALLS += target
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../3rdparty/quazip -lquazip
 OTHER_FILES += zip.dox
 DEFINES += QCADZIP_LIBRARY
-
-#POST_TARGETDEPS += ../../$$ROUTDIR/$${RLIBPRE}zip$${RLIBPOSTDLL}
