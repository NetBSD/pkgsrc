$NetBSD: patch-src_3rdparty_opennurbs_opennurbs_opennurbs.pro,v 1.3 2018/01/07 21:23:39 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

don't provide own zlib

force use of builtin alloca(3)

--- src/3rdparty/opennurbs/opennurbs/opennurbs.pro.orig	2017-12-19 14:26:30.000000000 +0000
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
+INSTALLS += target
+DEFINES += \"alloca(size)=__builtin_alloca(size)\"
 win32 {
     #DEFINES += ON_DLL_EXPORTS ON_COMPILING_OPENNURBS NDEBUG
     DEFINES += ON_COMPILING_OPENNURBS NDEBUG
