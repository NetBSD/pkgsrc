$NetBSD: patch-audio_softsynth_fluidsynth.cpp,v 1.1 2021/04/06 22:04:36 wiz Exp $

Fix build with fluidsynth 2.2.0

--- audio/softsynth/fluidsynth.cpp.orig	2020-09-13 21:05:37.000000000 +0000
+++ audio/softsynth/fluidsynth.cpp
@@ -144,11 +144,11 @@ static void *SoundFontMemLoader_open(con
 	return p;
 }
 
-static int SoundFontMemLoader_read(void *buf, int count, void *handle) {
+static int SoundFontMemLoader_read(void *buf, long long count, void *handle) {
 	return ((Common::SeekableReadStream *) handle)->read(buf, count) == (uint32)count ? FLUID_OK : FLUID_FAILED;
 }
 
-static int SoundFontMemLoader_seek(void *handle, long offset, int origin) {
+static int SoundFontMemLoader_seek(void *handle, long long offset, int origin) {
 	return ((Common::SeekableReadStream *) handle)->seek(offset, origin) ? FLUID_OK : FLUID_FAILED;
 }
 
@@ -157,7 +157,7 @@ static int SoundFontMemLoader_close(void
 	return FLUID_OK;
 }
 
-static long SoundFontMemLoader_tell(void *handle) {
+static long long SoundFontMemLoader_tell(void *handle) {
 	return ((Common::SeekableReadStream *) handle)->pos();
 }
 #endif
