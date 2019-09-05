$NetBSD: patch-src_snap_snap.pro,v 1.2 2019/09/05 13:39:10 nia Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/snap/snap.pro.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/snap/snap.pro
@@ -45,7 +45,10 @@ else {
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
 RC_FILE = snap.rc
