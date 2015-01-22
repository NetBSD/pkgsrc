$NetBSD: patch-FindPortaudio.cmake,v 1.2 2015/01/22 12:34:15 bouyer Exp $

really find portaudio in portaudio2 subdir

--- FindPortaudio.cmake.orig	2014-05-26 21:26:36.000000000 +0200
+++ FindPortaudio.cmake	2014-05-26 21:30:22.000000000 +0200
@@ -45,24 +45,13 @@
 set(PORTAUDIO_FOUND TRUE)
 else (PORTAUDIO_LIBRARIES AND PORTAUDIO_INCLUDE_DIRS)
 find_path(PORTAUDIO_INCLUDE_DIR
-NAMES
-portaudio.h
-PATHS
-/usr/include
-/usr/local/include
-/opt/local/include
-/sw/include
+NAMES "portaudio.h"
+PATH_SUFFIXES "portaudio2"
 )
 
 find_library(PORTAUDIO_LIBRARY
-NAMES
-portaudio
-PATHS
-/usr/lib
-/usr/local/lib
-/opt/local/lib
-/usr/lib/i386-linux-gnu
-/sw/lib
+NAMES "portaudio"
+PATH_SUFFIXES "portaudio2"
 )
 
 set(PORTAUDIO_INCLUDE_DIRS
