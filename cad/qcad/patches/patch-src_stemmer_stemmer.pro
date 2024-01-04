$NetBSD: patch-src_stemmer_stemmer.pro,v 1.5 2024/01/04 21:50:29 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/stemmer/stemmer.pro.orig	2023-09-04 18:51:52.000000000 +0000
+++ src/stemmer/stemmer.pro
@@ -8,8 +8,7 @@ TEMPLATE = lib
 CONFIG += plugin
 TARGET = $${RLIBNAME}stemmer
 LIBS += -lstemmer
+INSTALLS += target
 OTHER_FILES += stemmer.dox
 DEFINES += QCADSTEMMER_LIBRARY
 RC_FILE = stemmer.rc
-
-POST_TARGETDEPS += $$PWD/../../$$ROUTDIR/$${RLIBPRE}stemmer$${RLIBPOST}
