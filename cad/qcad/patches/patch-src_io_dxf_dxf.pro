$NetBSD: patch-src_io_dxf_dxf.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/io/dxf/dxf.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/io/dxf/dxf.pro
@@ -16,7 +16,12 @@ SOURCES = \
     RDxfPlugin.cpp
 TEMPLATE = lib
 DEFINES += QCADDXF_LIBRARY
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
@@ -24,5 +29,3 @@ r_static_libs {
 else {
     DESTDIR = ../../../plugins
 }
-
-POST_TARGETDEPS += ../../../$$ROUTDIR/$${RLIBPRE}dxflib$${RLIBPOST}
