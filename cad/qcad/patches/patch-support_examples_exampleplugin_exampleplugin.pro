$NetBSD: patch-support_examples_exampleplugin_exampleplugin.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- support/examples/exampleplugin/exampleplugin.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ support/examples/exampleplugin/exampleplugin.pro
@@ -6,4 +6,8 @@ TEMPLATE    = lib
 HEADERS     = RExamplePlugin.h
 SOURCES     = RExamplePlugin.cpp
 DESTDIR     = ../../../plugins
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}gui -l$${RLIBNAME}ecmaapi
+INSTALLS += target
+target.path= $${PREFIX}/lib/$${RLIBNAME}/plugins
+LIBS += -L../../../src/core -l$${RLIBNAME}core \
+	-L../../../src/gui -l$${RLIBNAME}gui \
+	-L../../../src/scripting/ecmaapi -l$${RLIBNAME}ecmaapi
