$NetBSD: patch-src_3rdparty_spatialindexnavel_spatialindexnavel.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/spatialindexnavel/spatialindexnavel.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/spatialindexnavel/spatialindexnavel.pro
@@ -8,6 +8,7 @@ r_static_libs {
 else {
     CONFIG += plugin
 }
+INSTALLS += target

 # this is required to compile the spatial index library from navel ltd:
 #DEFINES += PACKAGE_BUGREPORT=\\\"mhadji@gmail.com\\\"
