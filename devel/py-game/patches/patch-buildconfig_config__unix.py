$NetBSD: patch-buildconfig_config__unix.py,v 1.1 2019/06/06 21:46:12 adam Exp $

Detect X11R6 or X11R7; avoid localbase overriding search.
Use correct libpng.
Disable portmidi and porttime; porttime is a part of portmidi.

--- buildconfig/config_unix.py.orig	2019-06-06 17:38:22.000000000 +0000
+++ buildconfig/config_unix.py
@@ -148,8 +148,8 @@ def main(sdl2=False):
 
     #these get prefixes with '/usr' and '/usr/local' or the $LOCALBASE
     if sdl2:
-        origincdirs = ['/include', '/include/SDL2']
-        origlibdirs = ['/lib','/lib64','/X11R6/lib',
+        origincdirs = ['/include', '/include/SDL2', '/X11R6/include', '/X11R7/include']
+        origlibdirs = ['/lib','/lib64','/X11R6/lib', '/X11R7/lib',
                        '/lib/i386-linux-gnu', '/lib/x86_64-linux-gnu']
     else:
         origincdirs = ['/include', '/include/SDL', '/include/SDL']
@@ -216,13 +216,12 @@ def main(sdl2=False):
             #Dependency('GFX', 'SDL_gfxPrimitives.h', 'libSDL_gfx.so', ['SDL_gfx']),
         ]
     DEPS.extend([
-        Dependency('PNG', 'png.h', 'libpng', ['png']),
+        Dependency('PNG', 'png.h', 'libpng16', ['png']),
         Dependency('JPEG', 'jpeglib.h', 'libjpeg', ['jpeg']),
         Dependency('SCRAP', '', 'libX11', ['X11']),
         #Dependency('GFX', 'SDL_gfxPrimitives.h', 'libSDL_gfx.so', ['SDL_gfx']),
     ])
-    is_freebsd = platform.system() == 'FreeBSD'
-    if not is_freebsd:
+    if False:
         porttime_dep = get_porttime_dep()
         DEPS.append(
             Dependency('PORTMIDI', 'portmidi.h', 'libportmidi.so', ['portmidi'])
@@ -243,8 +242,8 @@ def main(sdl2=False):
     incdirs += ["/usr/local"+d for d in origincdirs]
     libdirs += ["/usr/local"+d for d in origlibdirs]
     if localbase:
-        incdirs = [localbase+d for d in origincdirs]
-        libdirs = [localbase+d for d in origlibdirs]
+        incdirs += [localbase+d for d in origincdirs]
+        libdirs += [localbase+d for d in origlibdirs]
 
     for arg in DEPS[0].cflags.split():
         if arg[:2] == '-I':
