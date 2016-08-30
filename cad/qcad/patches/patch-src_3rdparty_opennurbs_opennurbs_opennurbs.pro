$NetBSD: patch-src_3rdparty_opennurbs_opennurbs_opennurbs.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/3rdparty/opennurbs/opennurbs/opennurbs.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/opennurbs/opennurbs/opennurbs.pro
@@ -218,14 +218,9 @@ HEADERS += \

 TARGET = opennurbs
 TEMPLATE = lib
-CONFIG += staticlib
-CONFIG(release, debug|release) {
-    LIBS += -L../zlib/release
-}
-else {
-    LIBS += -L../zlib/debug
-}
-LIBS += -lzlib
+CONFIG += plugin
+LIBS += -L../zlib -lzlib
+INSTALLS += target
 win32 {
     #DEFINES += ON_DLL_EXPORTS ON_COMPILING_OPENNURBS NDEBUG
     DEFINES += ON_COMPILING_OPENNURBS NDEBUG
