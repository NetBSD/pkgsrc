$NetBSD: patch-src_core_core.pro,v 1.3 2018/07/27 14:12:41 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/core/core.pro.orig	2017-12-19 14:26:30.000000000 +0000
+++ src/core/core.pro
@@ -285,8 +285,9 @@ RESOURCES = resources/core.qrc
 RC_FILE = core.rc
 OTHER_FILES += core.dox math/math.dox
 DEFINES += QCADCORE_LIBRARY
+INSTALLS += target
 
-LIBS += -lopennurbs -lzlib
+LIBS += -L../3rdparty/opennurbs/opennurbs -lopennurbs
 
 win32 {
     LIBS += -lRpcrt4 -lAdvapi32
