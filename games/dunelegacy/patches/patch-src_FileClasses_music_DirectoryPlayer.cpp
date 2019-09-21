$NetBSD: patch-src_FileClasses_music_DirectoryPlayer.cpp,v 1.1 2019/09/21 12:34:24 nia Exp $

Initialize generic MIDI support for SDL2_mixer.

--- src/FileClasses/music/DirectoryPlayer.cpp.orig	2016-11-20 14:57:02.000000000 +0000
+++ src/FileClasses/music/DirectoryPlayer.cpp
@@ -61,7 +61,7 @@ DirectoryPlayer::DirectoryPlayer() : Mus
 
     music = nullptr;
 
-    Mix_Init(MIX_INIT_FLUIDSYNTH | MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
+    Mix_Init(MIX_INIT_MID | MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
 }
 
 DirectoryPlayer::~DirectoryPlayer() {
