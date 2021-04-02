$NetBSD: patch-src_io_dxf_dxf.pro,v 1.3 2021/04/02 20:27:12 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/io/dxf/dxf.pro.orig	2020-09-04 08:28:36.000000000 +0000
+++ src/io/dxf/dxf.pro
@@ -17,7 +17,12 @@ SOURCES = \
 TEMPLATE = lib
 DEFINES += QCADDXF_LIBRARY
 RC_FILE = dxf.rc
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}entity -ldxflib -l$${RLIBNAME}operations
+LIBS += -L../../core -l$${RLIBNAME}core \
+	-L../../entity -l$${RLIBNAME}entity \
+	-L../../3rdparty/dxflib -ldxflib \
+	-L../../operations -l$${RLIBNAME}operations
+INSTALLS += target
+target.path = $${PREFIX}/lib/$${RLIBNAME}/plugins
 r_static_libs {
     CONFIG -= plugin
     CONFIG += staticlib
@@ -25,5 +30,3 @@ r_static_libs {
 else {
     DESTDIR = $$PWD/../../../plugins
 }
-
-POST_TARGETDEPS +=  $$PWD/../../../$$ROUTDIR/$${RLIBPRE}dxflib$${RLIBPOST}
