$NetBSD: patch-src_3rdparty_quazip_quazip.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/quazip/quazip.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/quazip/quazip.pro
@@ -2,6 +2,7 @@ include( ../../../shared.pri )

 TARGET = quazip
 TEMPLATE = lib
+INSTALLS += target
 r_static_libs {
     CONFIG += staticlib
 }
