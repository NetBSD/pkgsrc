$NetBSD: patch-FindPortaudio.cmake,v 1.1 2014/05/25 18:26:57 bouyer Exp $

really find portaudio in portaudio2 subdir

--- FindPortaudio.cmake.orig	2013-05-08 17:41:43.000000000 +0200
+++ FindPortaudio.cmake	2014-05-24 21:28:16.000000000 +0200
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
