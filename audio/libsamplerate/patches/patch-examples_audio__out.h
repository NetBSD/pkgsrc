$NetBSD: patch-examples_audio__out.h,v 1.1 2017/04/24 10:08:40 maya Exp $

Declare AUDIO_OUT_s once and in audio_out.h

--- examples/audio_out.h.orig	2016-09-13 10:20:20.000000000 +0000
+++ examples/audio_out.h
@@ -6,7 +6,9 @@
 ** file at : https://github.com/erikd/libsamplerate/blob/master/COPYING
 */
 
-typedef	struct AUDIO_OUT_s AUDIO_OUT ;
+typedef	struct AUDIO_OUT_s
+{	int magic ;
+} AUDIO_OUT ;
 
 typedef int (*get_audio_callback_t) (void *callback_data, float *samples, int frames) ;
 
