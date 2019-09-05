$NetBSD: patch-src_customwidgets_customwidgets.pro,v 1.2 2019/09/05 13:39:10 nia Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/customwidgets/customwidgets.pro.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/customwidgets/customwidgets.pro
@@ -38,7 +38,10 @@ HEADERS = RShortcutLineEditPlugin.h \
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
 RC_FILE = customwidgets.rc
