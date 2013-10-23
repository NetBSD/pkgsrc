$NetBSD: patch-module_setup.py,v 1.1 2013/10/23 11:35:46 ryoon Exp $

* png from pkgsrc is libpng16.so

--- module/setup.py.orig	2013-06-08 02:38:29.000000000 +0000
+++ module/setup.py
@@ -33,7 +33,7 @@ include("libswscale/swscale.h")
 include("GL/glew.h")
 
 library("SDL")
-library("png")
+library("png16")
 library("avformat")
 library("avcodec")
 library("avutil")
