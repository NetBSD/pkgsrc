$NetBSD: patch-qt_config.tests_unix_libpng_libpng.pro,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/config.tests/unix/libpng/libpng.pro.orig	2017-09-10 11:25:06.276114904 +0000
+++ qt/config.tests/unix/libpng/libpng.pro
@@ -1,4 +1,4 @@
 SOURCES = libpng.cpp
 CONFIG -= qt dylib
 mac:CONFIG -= app_bundle
-LIBS += -lpng
+LIBS += ${COMPILER_RPATH_FLAG}${PREFIX}/lib -lpng
