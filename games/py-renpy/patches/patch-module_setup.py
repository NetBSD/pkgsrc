$NetBSD: patch-module_setup.py,v 1.3 2023/03/10 21:14:39 ryoon Exp $

* png from pkgsrc is libpng16.so
* Suppot Python 3.11
  From: https://github.com/renpy/renpy/commit/72815a4915ecb43999f75ff0aaf78ba66020f9aa

--- module/setup.py.orig	2022-09-08 03:49:02.959533000 +0000
+++ module/setup.py
@@ -56,7 +56,7 @@ setup_env("LD")
 setup_env("CXX")
 
 import setuplib
-from setuplib import android, ios, emscripten, raspi, include, library, cython, cmodule, copyfile, find_unnecessary_gen, generate_all_cython
+from setuplib import android, ios, emscripten, raspi, include, library, cython, cmodule, copyfile, find_unnecessary_gen, generate_all_cython, PY2
 
 # These control the level of optimization versus debugging.
 setuplib.extra_compile_args = [ "-Wno-unused-function" ]
@@ -88,7 +88,7 @@ include("GL/glew.h")
 include("pygame_sdl2/pygame_sdl2.h", directory="python{}.{}".format(sys.version_info.major, sys.version_info.minor))
 
 library("SDL2")
-library("png")
+library("png16")
 library("avformat")
 library("avcodec")
 library("avutil")
@@ -173,7 +173,8 @@ cython("renpy.pydict")
 cython("renpy.style")
 
 # renpy.compat
-cython("renpy.compat.dictviews")
+if PY2:
+    cython("renpy.compat.dictviews")
 
 # renpy.styledata
 cython("renpy.styledata.styleclass")
