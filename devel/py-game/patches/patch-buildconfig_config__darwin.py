$NetBSD: patch-buildconfig_config__darwin.py,v 1.4 2023/10/29 19:05:49 adam Exp $

Use correct libpng.

--- buildconfig/config_darwin.py.orig	2023-08-14 07:36:16.000000000 +0000
+++ buildconfig/config_darwin.py
@@ -130,7 +130,7 @@ def main(auto_config=False):
     ]
 
     DEPS.extend([
-        Dependency('PNG', 'png.h', 'libpng', ['png']),
+        Dependency('PNG', 'png.h', 'libpng16', ['png']),
         Dependency('JPEG', 'jpeglib.h', 'libjpeg', ['jpeg']),
         Dependency('PORTMIDI', 'portmidi.h', 'libportmidi', ['portmidi']),
         Dependency('PORTTIME', 'porttime.h', '', []),
