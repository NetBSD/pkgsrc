$NetBSD: patch-src-qt5-rpcemu.pro,v 1.1 2020/10/24 16:33:34 js Exp $

Add a define to figure out network-related files are compiled.

Disable debug mode to avoid error about QtWidgets_debug missing.

--- src/qt5/rpcemu.pro.orig	2020-05-06 19:19:23.000000000 +0000
+++ src/qt5/rpcemu.pro
@@ -1,6 +1,6 @@
 # http://doc.qt.io/qt-5/qmake-tutorial.html
 
-CONFIG += debug_and_release
+CONFIG += release
 
 
 QT += core widgets gui multimedia
@@ -125,6 +125,7 @@ win32 { 
 			keyboard_win.c
 	HEADERS +=	../network.h \
 			network_dialog.h
+	DEFINES +=	CONFIG_NETWORK
 
 	RC_ICONS = ../win/rpcemu.ico
 
@@ -139,6 +140,7 @@ linux {
 			network_dialog.cpp
 	HEADERS +=	../network.h \
 			network_dialog.h
+	DEFINES +=	CONFIG_NETWORK
 }
 
 unix {
