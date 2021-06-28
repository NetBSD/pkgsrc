$NetBSD: patch-music__fluidsynth.c,v 1.1 2021/06/28 12:11:16 micha Exp $

A bug in SDL2_Mixer <= 2.0.4 will crash fluidsynth >= 2.1.6 because the
objects are destroyed in an illegal order.
https://www.fluidsynth.org/news/2021/01/23/sdl2-mixer-bug/
https://github.com/libsdl-org/SDL_mixer/commit/6160668079f91d57a5d7bf0b40ffdd843be70daf

--- music_fluidsynth.c.orig	2018-10-31 14:59:00.000000000 +0000
+++ music_fluidsynth.c
@@ -273,9 +273,10 @@ static void FLUIDSYNTH_Stop(void *contex
 static void FLUIDSYNTH_Delete(void *context)
 {
     FLUIDSYNTH_Music *music = (FLUIDSYNTH_Music *)context;
+    fluid_settings_t *settings = fluidsynth.fluid_synth_get_settings(music->synth);
     fluidsynth.delete_fluid_player(music->player);
-    fluidsynth.delete_fluid_settings(fluidsynth.fluid_synth_get_settings(music->synth));
     fluidsynth.delete_fluid_synth(music->synth);
+    fluidsynth.delete_fluid_settings(settings);
     SDL_free(music);
 }
 
