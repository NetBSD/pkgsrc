$NetBSD: patch-src_stemmer_stemmer.pro,v 1.3 2021/04/02 20:27:12 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/stemmer/stemmer.pro.orig	2020-09-04 08:28:36.000000000 +0000
+++ src/stemmer/stemmer.pro
@@ -7,9 +7,8 @@ HEADERS = \
 TEMPLATE = lib
 CONFIG += plugin
 TARGET = $${RLIBNAME}stemmer
-LIBS += -lstemmer
+LIBS += -L../3rdparty/stemmer -lstemmer
+INSTALLS += target
 OTHER_FILES += stemmer.dox
 DEFINES += QCADSTEMMER_LIBRARY
 RC_FILE = stemmer.rc
-
-POST_TARGETDEPS += $$PWD/../../$$ROUTDIR/$${RLIBPRE}stemmer$${RLIBPOST}
