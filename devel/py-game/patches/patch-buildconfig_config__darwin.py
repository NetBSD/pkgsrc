$NetBSD: patch-buildconfig_config__darwin.py,v 1.1 2019/06/06 21:46:12 adam Exp $

Use correct libpng.

--- buildconfig/config_darwin.py.orig	2019-04-25 06:14:17.000000000 +0000
+++ buildconfig/config_darwin.py
@@ -150,7 +150,7 @@ def main(sdl2=False):
     DEPS.extend([
         FrameworkDependency('PORTTIME', 'CoreMidi.h', 'CoreMidi', 'CoreMIDI'),
         FrameworkDependency('QUICKTIME', 'QuickTime.h', 'QuickTime', 'QuickTime'),
-        Dependency('PNG', 'png.h', 'libpng', ['png']),
+        Dependency('PNG', 'png.h', 'libpng16', ['png']),
         Dependency('JPEG', 'jpeglib.h', 'libjpeg', ['jpeg']),
         Dependency('PORTMIDI', 'portmidi.h', 'libportmidi', ['portmidi']),
         find_freetype(),
