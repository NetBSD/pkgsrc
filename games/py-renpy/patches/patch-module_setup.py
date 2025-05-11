$NetBSD: patch-module_setup.py,v 1.5 2025/05/11 14:08:33 ryoon Exp $

* png from pkgsrc is libpng16.so

--- module/setup.py.orig	2025-02-23 12:22:19.115359800 +0000
+++ module/setup.py
@@ -89,7 +89,7 @@ include("pygame_sdl2/pygame_sdl2.h", dir
 include("hb.h", directory="harfbuzz")
 
 library("SDL2")
-library("png")
+library("png16")
 library("avformat")
 library("avcodec")
 library("avutil")
