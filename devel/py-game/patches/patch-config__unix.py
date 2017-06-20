$NetBSD: patch-config__unix.py,v 1.1 2017/06/20 17:00:07 adam Exp $

Detect X11R7
Disable portmidi and porttime; porttime is a part of portmidi

--- config_unix.py.orig	2016-08-20 20:28:55.000000000 +0000
+++ config_unix.py
@@ -16,7 +16,7 @@ localbase = os.environ.get('LOCALBASE', 
 
 #these get prefixes with '/usr' and '/usr/local' or the $LOCALBASE
 origincdirs = ['/include', '/include/SDL', '/include/SDL']
-origlibdirs = ['/lib','/lib64','/X11R6/lib']
+origlibdirs = ['/lib','/lib64','/X11R6/lib','/X11R7/lib']
 if 'ORIGLIBDIRS' in os.environ and os.environ['ORIGLIBDIRS'] != "":
     origlibdirs = os.environ['ORIGLIBDIRS'].split(":")
 
@@ -169,18 +169,15 @@ def main():
         else:
             return Dependency('PORTTIME', 'porttime.h', 'libporttime.so', ['porttime'])
 
-    porttime_dep = get_porttime_dep()
 
     DEPS = [
         DependencyProg('SDL', 'SDL_CONFIG', 'sdl-config', '1.2', ['sdl']),
         Dependency('FONT', 'SDL_ttf.h', 'libSDL_ttf.so', ['SDL_ttf']),
         Dependency('IMAGE', 'SDL_image.h', 'libSDL_image.so', ['SDL_image']),
         Dependency('MIXER', 'SDL_mixer.h', 'libSDL_mixer.so', ['SDL_mixer']),
-        Dependency('PNG', 'png.h', 'libpng', ['png']),
+        Dependency('PNG', 'png.h', 'libpng16', ['png']),
         Dependency('JPEG', 'jpeglib.h', 'libjpeg', ['jpeg']),
         Dependency('SCRAP', '', 'libX11', ['X11']),
-        Dependency('PORTMIDI', 'portmidi.h', 'libportmidi.so', ['portmidi']),
-        porttime_dep,
         DependencyProg('FREETYPE', 'FREETYPE_CONFIG', 'freetype-config', '2.0',
                        ['freetype'], '--ftversion'),
         #Dependency('GFX', 'SDL_gfxPrimitives.h', 'libSDL_gfx.so', ['SDL_gfx']),
