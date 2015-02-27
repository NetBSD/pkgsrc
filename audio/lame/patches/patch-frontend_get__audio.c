$NetBSD: patch-frontend_get__audio.c,v 1.1 2015/02/27 19:49:16 snj Exp $

https://bugs.debian.org/777159

--- frontend/get_audio.c.orig	2012-02-14 02:35:58.000000000 -0800
+++ frontend/get_audio.c	2015-02-27 11:15:11.000000000 -0800
@@ -1448,6 +1448,10 @@ parse_wave_header(lame_global_flags * gf
         else {
             (void) lame_set_in_samplerate(gfp, global_reader.input_samplerate);
         }
+        /* avoid division by zero */
+        if (bits_per_sample < 1)
+            return -1;
+
         global. pcmbitwidth = bits_per_sample;
         global. pcm_is_unsigned_8bit = 1;
         global. pcm_is_ieee_float = (format_tag == WAVE_FORMAT_IEEE_FLOAT ? 1 : 0);
