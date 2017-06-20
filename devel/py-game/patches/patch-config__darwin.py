$NetBSD: patch-config__darwin.py,v 1.1 2017/06/20 17:00:07 adam Exp $

Use correct lib for PNG.

--- config_darwin.py.orig	2017-06-20 16:20:16.000000000 +0000
+++ config_darwin.py
@@ -109,7 +109,7 @@ DEPS = [
          FrameworkDependency('MIXER', 'SDL_mixer.h', 'libSDL_mixer', 'SDL_mixer')],
     FrameworkDependency('PORTTIME', 'CoreMidi.h', 'CoreMidi', 'CoreMIDI'),
     FrameworkDependency('QUICKTIME', 'QuickTime.h', 'QuickTime', 'QuickTime'),
-    Dependency('PNG', 'png.h', 'libpng', ['png']),
+    Dependency('PNG', 'png.h', 'libpng16', ['png']),
     Dependency('JPEG', 'jpeglib.h', 'libjpeg', ['jpeg']),
     Dependency('PORTMIDI', 'portmidi.h', 'libportmidi', ['portmidi']),
     #DependencyProg('FREETYPE', 'FREETYPE_CONFIG', '/usr/X11R6/bin/freetype-config', '2.0',
