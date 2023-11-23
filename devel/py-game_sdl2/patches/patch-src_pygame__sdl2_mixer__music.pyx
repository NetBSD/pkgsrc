$NetBSD: patch-src_pygame__sdl2_mixer__music.pyx,v 1.1 2023/11/23 15:39:05 ryoon Exp $

--- src/pygame_sdl2/mixer_music.pyx.orig	2023-11-21 07:03:36.136395079 +0000
+++ src/pygame_sdl2/mixer_music.pyx
@@ -27,7 +27,7 @@ cdef Mix_Music *current_music = NULL
 cdef object queued_music = None
 cdef int endevent = 0
 
-cdef void music_finished():
+cdef void music_finished() noexcept:
     global queued_music
     if queued_music:
         load(queued_music)
