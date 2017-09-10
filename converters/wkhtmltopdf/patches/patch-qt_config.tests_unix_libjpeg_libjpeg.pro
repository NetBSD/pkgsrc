$NetBSD: patch-qt_config.tests_unix_libjpeg_libjpeg.pro,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/config.tests/unix/libjpeg/libjpeg.pro.orig	2017-09-10 11:25:23.534649648 +0000
+++ qt/config.tests/unix/libjpeg/libjpeg.pro
@@ -1,4 +1,4 @@
 SOURCES = libjpeg.cpp
 CONFIG -= qt dylib
 mac:CONFIG -= app_bundle
-LIBS += -ljpeg
+LIBS += ${COMPILER_RPATH_FLAG}${PREFIX}/lib -ljpeg
