$NetBSD: patch-examples_audio_out.c,v 1.2 2017/04/24 10:08:40 maya Exp $

Fix building on Mac OS X.
declare typedef AUDIO_OUT_s once and in audio_out.h

--- examples/audio_out.c.orig	2016-09-13 10:20:20.000000000 +0000
+++ examples/audio_out.c
@@ -33,11 +33,6 @@
 #define MAKE_MAGIC(a,b,c,d,e,f,g,h)		\
 			((a) + ((b) << 1) + ((c) << 2) + ((d) << 3) + ((e) << 4) + ((f) << 5) + ((g) << 6) + ((h) << 7))
 
-typedef	struct AUDIO_OUT_s
-{	int magic ;
-} AUDIO_OUT ;
-
-
 /*------------------------------------------------------------------------------
 **	Linux (ALSA and OSS) functions for playing a sound.
 */
@@ -432,7 +427,6 @@ opensoundsys_close (AUDIO_OUT *audio_out
 
 #if (defined (__MACH__) && defined (__APPLE__)) /* MacOSX */
 
-#include <Carbon.h>
 #include <CoreAudio/AudioHardware.h>
 
 #define	MACOSX_MAGIC	MAKE_MAGIC ('M', 'a', 'c', ' ', 'O', 'S', ' ', 'X')
