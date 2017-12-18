$NetBSD: patch-src_3rdparty_dxflib_dxflib.pro,v 1.2 2017/12/18 21:21:44 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/dxflib/dxflib.pro.orig	2017-07-21 17:57:53.000000000 +0000
+++ src/3rdparty/dxflib/dxflib.pro
@@ -25,6 +25,7 @@ SOURCES = \
 
 TARGET = dxflib
 TEMPLATE = lib
-CONFIG += staticlib
+CONFIG += plugin
+INSTALLS += target
 CONFIG -= qt
 DEFINES += DXFLIB_LIBRARY
