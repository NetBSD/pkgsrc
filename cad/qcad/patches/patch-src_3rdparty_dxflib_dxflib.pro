$NetBSD: patch-src_3rdparty_dxflib_dxflib.pro,v 1.3 2019/09/05 13:39:10 nia Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/dxflib/dxflib.pro.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/3rdparty/dxflib/dxflib.pro
@@ -25,7 +25,8 @@ SOURCES = \
 
 TARGET = dxflib
 TEMPLATE = lib
-CONFIG += staticlib
+CONFIG += plugin
+INSTALLS += target
 CONFIG -= qt
 DEFINES += DXFLIB_LIBRARY
 RC_FILE = dxflib.rc
