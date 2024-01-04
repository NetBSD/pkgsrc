$NetBSD: patch-src_3rdparty_legacy_spatialindexnavel_spatialindexnavel.pro,v 1.1 2024/01/04 21:50:29 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/legacy/spatialindexnavel/spatialindexnavel.pro.orig	2024-01-02 10:23:10.005973179 +0000
+++ src/3rdparty/legacy/spatialindexnavel/spatialindexnavel.pro
@@ -8,6 +8,7 @@ r_static_libs {
 else {
     CONFIG += plugin
 }
+INSTALLS+= target
 
 # this is required to compile the spatial index library from navel ltd:
 #DEFINES += PACKAGE_BUGREPORT=\\\"mhadji@gmail.com\\\"
