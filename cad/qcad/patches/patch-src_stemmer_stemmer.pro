$NetBSD: patch-src_stemmer_stemmer.pro,v 1.2 2018/07/27 14:12:41 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/stemmer/stemmer.pro.orig	2017-12-19 14:26:30.000000000 +0000
+++ src/stemmer/stemmer.pro
@@ -7,9 +7,10 @@ HEADERS = \
 TEMPLATE = lib
 CONFIG += plugin
 TARGET = $${RLIBNAME}stemmer
-LIBS += -lstemmer
+LIBS += -L../3rdparty/stemmer -lstemmer
+INSTALLS += target
 OTHER_FILES += stemmer.dox
 DEFINES += QCADSTEMMER_LIBRARY
 RC_FILE = stemmer.rc
 
-POST_TARGETDEPS += ../../$$ROUTDIR/$${RLIBPRE}stemmer$${RLIBPOST}
+#POST_TARGETDEPS += ../../$$ROUTDIR/$${RLIBPRE}stemmer$${RLIBPOST}
