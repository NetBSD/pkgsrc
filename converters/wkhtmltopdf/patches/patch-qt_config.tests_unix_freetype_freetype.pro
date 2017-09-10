$NetBSD: patch-qt_config.tests_unix_freetype_freetype.pro,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/config.tests/unix/freetype/freetype.pro.orig	2017-09-10 11:24:46.252716190 +0000
+++ qt/config.tests/unix/freetype/freetype.pro
@@ -1,5 +1,5 @@
 SOURCES = freetype.cpp
 CONFIG += x11
 CONFIG -= qt
-LIBS += -lfreetype
+LIBS += ${COMPILER_RPATH_FLAG}${X11PREFIX}/lib -lfreetype
 include(freetype.pri)
