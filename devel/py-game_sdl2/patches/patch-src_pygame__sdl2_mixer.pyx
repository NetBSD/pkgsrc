$NetBSD: patch-src_pygame__sdl2_mixer.pyx,v 1.1 2023/11/23 15:39:05 ryoon Exp $

--- src/pygame_sdl2/mixer.pyx.orig	2023-11-21 07:03:05.449771728 +0000
+++ src/pygame_sdl2/mixer.pyx
@@ -57,7 +57,7 @@ def _play_current(int channel):
             Mix_PlayChannelTimed(channel, next_sound.chunk, 0, -1)
 
 
-cdef void channel_callback(int channel) with gil:
+cdef void channel_callback(int channel) noexcept with gil:
 
     cdef int etype = 0
     cdef SDL_Event e
