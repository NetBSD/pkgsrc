$NetBSD: patch-cogl_cogl-texture-2d.c,v 1.1 2014/01/03 12:32:24 obache Exp $

* Fix build on big-endian
  https://git.gnome.org/browse/cogl/commit/?h=cogl-1.16&id=ee87fcb7427962047c811c9fab0e0a4237134243

--- cogl/cogl-texture-2d.c.orig	2013-08-19 21:23:00.000000000 +0000
+++ cogl/cogl-texture-2d.c
@@ -315,7 +315,7 @@ cogl_wayland_texture_2d_new_from_buffer 
           case WL_SHM_FORMAT_ARGB8888:
             format = COGL_PIXEL_FORMAT_ARGB_8888_PRE;
             break;
-          case WL_SHM_FORMAT_XRGB32:
+          case WL_SHM_FORMAT_XRGB8888:
             format = COGL_PIXEL_FORMAT_ARGB_8888;
             internal_format = COGL_PIXEL_FORMAT_RGB_888;
             break;
