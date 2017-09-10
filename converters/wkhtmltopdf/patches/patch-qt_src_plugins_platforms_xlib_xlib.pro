$NetBSD: patch-qt_src_plugins_platforms_xlib_xlib.pro,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/plugins/platforms/xlib/xlib.pro.orig	2017-09-10 11:24:02.421497627 +0000
+++ qt/src/plugins/platforms/xlib/xlib.pro
@@ -30,7 +30,7 @@ HEADERS = \
         qxlibdisplay.h \
         qxlibnativeinterface.h
 
-LIBS += -lX11 -lXext
+LIBS += ${COMPILER_RPATH_FLAG}${X11PREFIX}/lib -lX11 -lXext
 
 mac {
     LIBS += -L/usr/X11/lib -lz -framework Carbon
