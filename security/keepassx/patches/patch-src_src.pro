$NetBSD: patch-src_src.pro,v 1.1 2012/07/03 18:37:55 schwarz Exp $

--- src/src.pro.orig	2012-06-30 20:01:34.000000000 +0200
+++ src/src.pro	2012-06-30 20:02:23.000000000 +0200
@@ -8,7 +8,7 @@
 data.files += ../share/keepass/* 
 TARGET = ../bin/keepass
 
-unix:!macx{
+unix{
 	isEmpty(PREFIX){
 		PREFIX=/usr/local
 	}
@@ -18,12 +18,6 @@
 	SOURCES+=lib/AutoType_X11.cpp
 }
 
-macx{ 
-	target.path = /Applications
-	data.path = /Applications/keepass.app/Contents/share/keepass
-	SOURCES+=lib/AutoType_X11.cpp
-}
-
 win32{
 	SOURCES+=lib/AutoType_Win.cpp
 	TARGET=../$$TARGET
