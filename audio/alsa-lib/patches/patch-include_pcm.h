$NetBSD: patch-include_pcm.h,v 1.1 2012/01/02 04:06:24 sbd Exp $

--- include/pcm.h.orig	2009-12-16 15:18:51.000000000 +0000
+++ include/pcm.h
@@ -456,7 +456,9 @@ int snd_pcm_wait(snd_pcm_t *pcm, int tim
 int snd_pcm_link(snd_pcm_t *pcm1, snd_pcm_t *pcm2);
 int snd_pcm_unlink(snd_pcm_t *pcm);
 
+/*
 //int snd_pcm_mixer_element(snd_pcm_t *pcm, snd_mixer_t *mixer, snd_mixer_elem_t **elem);
+ */
 
 /*
  * application helpers - these functions are implemented on top
