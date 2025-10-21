$NetBSD: patch-src_audio_alsa_SDL__alsa__audio.c,v 1.1.2.2 2025/10/21 02:25:03 maya Exp $

* Make compatible with alsa-lib-1.2.14 to fix alsa option build with GCC 14.

--- src/audio/alsa/SDL_alsa_audio.c.orig	2025-10-07 15:41:55.292495535 +0000
+++ src/audio/alsa/SDL_alsa_audio.c
@@ -88,7 +88,7 @@ static const char *(*ALSA_snd_pcm_info_g
 static int (*ALSA_snd_pcm_info_get_card)(const snd_pcm_info_t *);
 static int (*ALSA_snd_card_get_name)(int, char **);
 static int (*ALSA_snd_pcm_info_malloc)(snd_pcm_info_t **);
-static int (*ALSA_snd_pcm_info_free)(snd_pcm_info_t *);
+static void (*ALSA_snd_pcm_info_free)(snd_pcm_info_t *);
 #ifdef SND_CHMAP_API_VERSION
 static snd_pcm_chmap_t *(*ALSA_snd_pcm_get_chmap)(snd_pcm_t *);
 static int (*ALSA_snd_pcm_chmap_print)(const snd_pcm_chmap_t *map, size_t maxlen, char *buf);
