$NetBSD: patch-render__sdl.c,v 1.1 2024/11/04 21:39:04 nia Exp $

Fix audio output on NetBSD - floats unsupported.

--- render_sdl.c.orig	2024-11-04 21:34:19.095086183 +0000
+++ render_sdl.c
@@ -1038,7 +1038,7 @@ static void init_audio()
    		rate = 48000;
    	}
     desired.freq = rate;
-	desired.format = AUDIO_F32SYS;
+	desired.format = AUDIO_S16SYS;
 	desired.channels = 2;
     char * samples_str = tern_find_path(config, "audio\0buffer\0", TVAL_PTR).ptrval;
    	int samples = samples_str ? atoi(samples_str) : 0;
