$NetBSD: patch-src_customwidgets_customwidgets.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/customwidgets/customwidgets.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/customwidgets/customwidgets.pro
@@ -36,6 +36,9 @@ HEADERS = RShortcutLineEditPlugin.h \
 #    HEADERS += RWebViewPlugin.h
 #}
 TEMPLATE = lib
-LIBS += -l$${RLIBNAME}gui -l$${RLIBNAME}core
+LIBS += -L../gui -l$${RLIBNAME}gui \
+	-L../core -l$${RLIBNAME}core
+INSTALLS += target
+target.path = $${PREFIX}/lib/$${RLIBNAME}/plugins/designer
 DESTDIR = ../../plugins/designer
 OTHER_FILES += customwidgets.dox
