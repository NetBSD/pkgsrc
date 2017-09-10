$NetBSD: patch-qt_config.tests_x11_mitshm_mitshm.pro,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/config.tests/x11/mitshm/mitshm.pro.orig	2017-09-10 11:24:26.728648117 +0000
+++ qt/config.tests/x11/mitshm/mitshm.pro
@@ -1,5 +1,5 @@
 SOURCES = mitshm.cpp
 CONFIG += x11
 CONFIG -= qt
-LIBS += -lXext
+LIBS += ${COMPILER_RPATH_FLAG}${X11PREFIX}/lib -lXext
 hpux*:DEFINES+=Q_OS_HPUX
