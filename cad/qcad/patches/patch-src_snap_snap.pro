$NetBSD: patch-src_snap_snap.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/snap/snap.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/snap/snap.pro
@@ -45,6 +45,9 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}snap
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}grid -l$${RLIBNAME}entity
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../grid -l$${RLIBNAME}grid \
+	-L../entity -l$${RLIBNAME}entity
+INSTALLS += target
 OTHER_FILES += snap.dox
 DEFINES += QCADSNAP_LIBRARY
