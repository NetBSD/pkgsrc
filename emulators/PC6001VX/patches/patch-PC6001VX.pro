$NetBSD: patch-PC6001VX.pro,v 1.4 2018/01/07 20:58:56 joerg Exp $

--- PC6001VX.pro.orig	2018-01-06 22:35:44.312596832 +0000
+++ PC6001VX.pro
@@ -37,6 +37,7 @@ INCLUDEPATH += src/Qt src/Qt/qtsingleapp
 
 #Configuration for UNIX variants
 unix {
+QMAKE_RPATHDIR = $(PREFIX)/lib/ffmpeg3
 #Configuration for Android
 android {
 DEFINES += NOSINGLEAPP NOJOYSTICK NOMONITOR NOAVI ALWAYSFULLSCREEN AUTOSUSPEND
