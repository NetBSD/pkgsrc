$NetBSD: patch-src_pygame__sdl2_image.pyx,v 1.1 2023/11/23 15:39:05 ryoon Exp $

--- src/pygame_sdl2/image.pyx.orig	2023-11-21 05:06:52.531403700 +0000
+++ src/pygame_sdl2/image.pyx
@@ -147,10 +147,10 @@ def load(fi, namehint="", size=None):
         return surf
 
 cdef extern from "write_jpeg.h":
-    int Pygame_SDL2_SaveJPEG(SDL_Surface *, char *, int) nogil
+    int Pygame_SDL2_SaveJPEG(SDL_Surface *, char *, int) noexcept nogil
 
 cdef extern from "write_png.h":
-    int Pygame_SDL2_SavePNG(const char *, SDL_Surface *, int) nogil
+    int Pygame_SDL2_SavePNG(const char *, SDL_Surface *, int) noexcept nogil
 
 def save(Surface surface not None, filename, compression=-1):
 
