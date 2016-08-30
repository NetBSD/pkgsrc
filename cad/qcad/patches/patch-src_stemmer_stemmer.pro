$NetBSD: patch-src_stemmer_stemmer.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/stemmer/stemmer.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/stemmer/stemmer.pro
@@ -7,8 +7,7 @@ HEADERS = \
 TEMPLATE = lib
 CONFIG += plugin
 TARGET = $${RLIBNAME}stemmer
-LIBS += -lstemmer
+LIBS += -L../3rdparty/stemmer -lstemmer
+INSTALLS += target
 OTHER_FILES += stemmer.dox
 DEFINES += QCADSTEMMER_LIBRARY
-
-POST_TARGETDEPS += ../../$$ROUTDIR/$${RLIBPRE}stemmer$${RLIBPOST}
