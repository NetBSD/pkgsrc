$NetBSD: patch-Tarsnap.pro,v 1.1 2016/05/07 10:10:46 joerg Exp $

--- Tarsnap.pro.orig	2016-05-06 18:45:38.000000000 +0000
+++ Tarsnap.pro
@@ -12,6 +12,8 @@ DEFINES += APP_VERSION=\\\"$$VERSION\\\"
 #QMAKE_TARGET_DESCRIPTION = GUI frontend for Tarsnap
 #QMAKE_TARGET_COPYRIGHT = copyright Tarsnap Backup Inc.
 
+QMAKE_LFLAGS += ${COMPILER_RPATH_FLAG}${X11BASE}/lib
+
 SOURCES += \
     src/coreapplication.cpp \
     src/main.cpp \
