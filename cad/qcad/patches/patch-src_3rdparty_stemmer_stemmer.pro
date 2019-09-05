$NetBSD: patch-src_3rdparty_stemmer_stemmer.pro,v 1.2 2019/09/05 13:39:10 nia Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/stemmer/stemmer.pro.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/3rdparty/stemmer/stemmer.pro
@@ -44,5 +44,5 @@ HEADERS += \
 
 TARGET = stemmer
 TEMPLATE = lib
-CONFIG += staticlib
-#CONFIG += plugin
+CONFIG += plugin
+INSTALLS += target
