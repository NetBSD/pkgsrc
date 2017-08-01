$NetBSD: patch-Tarsnap.pro,v 1.2 2017/08/01 15:51:53 wiz Exp $

--- Tarsnap.pro.orig	2017-07-10 08:43:23.000000000 +0000
+++ Tarsnap.pro
@@ -14,6 +14,8 @@ DEFINES += APP_VERSION=\\\"$$VERSION\\\"
 #QMAKE_TARGET_DESCRIPTION = GUI frontend for Tarsnap
 #QMAKE_TARGET_COPYRIGHT = copyright Tarsnap Backup Inc.
 
+QMAKE_LFLAGS += ${COMPILER_RPATH_FLAG}${X11BASE}/lib ${LDFLAGS}
+
 SOURCES += \
     src/main.cpp \
     src/coreapplication.cpp \
