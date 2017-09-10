$NetBSD: patch-qt_config.tests_x11_xrender_xrender.pro,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/config.tests/x11/xrender/xrender.pro.orig	2017-09-10 11:25:41.279541527 +0000
+++ qt/config.tests/x11/xrender/xrender.pro
@@ -1,4 +1,4 @@
 SOURCES = xrender.cpp
 CONFIG += x11
 CONFIG -= qt
-LIBS += -lXrender
+LIBS += ${COMPILER_RPATH_FLAG}${X11PREFIX}/lib -lXrender
