$NetBSD: patch-src_gui_gui.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/gui/gui.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/gui/gui.pro
@@ -80,9 +80,11 @@ else {
     CONFIG += plugin
 }

-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}entity
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../entity -l$${RLIBNAME}entity
 NAME = $${RLIBNAME}gui
 TARGET = $${NAME}
+INSTALLS += target
 OTHER_FILES += gui.dox
 DEFINES += QCADGUI_LIBRARY
 !win32:include( ../../shared_ts.pri )
