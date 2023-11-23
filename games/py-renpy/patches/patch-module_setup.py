$NetBSD: patch-module_setup.py,v 1.4 2023/11/23 15:41:21 ryoon Exp $

* png from pkgsrc is libpng16.so

--- module/setup.py.orig	2022-09-08 03:49:02.959533000 +0000
+++ module/setup.py
@@ -88,7 +88,7 @@ include("GL/glew.h")
 include("pygame_sdl2/pygame_sdl2.h", directory="python{}.{}".format(sys.version_info.major, sys.version_info.minor))
 
 library("SDL2")
-library("png")
+library("png16")
 library("avformat")
 library("avcodec")
 library("avutil")
