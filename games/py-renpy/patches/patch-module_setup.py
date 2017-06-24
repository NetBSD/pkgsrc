$NetBSD: patch-module_setup.py,v 1.2 2017/06/24 19:39:47 adam Exp $

* png from pkgsrc is libpng16.so

--- module/setup.py.orig	2014-08-05 01:19:58.000000000 +0000
+++ module/setup.py
@@ -75,7 +75,7 @@ include("libswscale/swscale.h")
 include("GL/glew.h")
 
 library("SDL")
-library("png")
+library("png16")
 library("avformat")
 library("avcodec")
 library("avutil")
