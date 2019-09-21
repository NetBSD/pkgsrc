$NetBSD: patch-src_FileClasses_music_XMIPlayer.cpp,v 1.1 2019/09/21 12:34:24 nia Exp $

Initialize generic MIDI support for SDL2_mixer.

--- src/FileClasses/music/XMIPlayer.cpp.orig	2016-11-17 23:06:11.000000000 +0000
+++ src/FileClasses/music/XMIPlayer.cpp
@@ -32,7 +32,7 @@
 XMIPlayer::XMIPlayer() : MusicPlayer(settings.audio.playMusic, settings.audio.musicVolume) {
     music = nullptr;
 
-    if((Mix_Init(MIX_INIT_FLUIDSYNTH) & MIX_INIT_FLUIDSYNTH) == 0) {
+    if((Mix_Init(MIX_INIT_MID) & MIX_INIT_MID) == 0) {
         SDL_Log("XMIPlayer: Failed to init required midi support: %s", SDL_GetError());
     }
 }
