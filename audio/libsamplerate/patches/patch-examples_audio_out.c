$NetBSD: patch-examples_audio_out.c,v 1.1 2012/07/04 08:59:23 adam Exp $

Fix building on Mac OS X.

--- examples/audio_out.c.orig	2012-06-22 20:14:44.000000000 +0000
+++ examples/audio_out.c
@@ -168,7 +168,6 @@ linux_close (AUDIO_OUT *audio_out)
 
 #if (defined (__MACH__) && defined (__APPLE__)) /* MacOSX */
 
-#include <Carbon.h>
 #include <CoreAudio/AudioHardware.h>
 
 #define	MACOSX_MAGIC	MAKE_MAGIC ('M', 'a', 'c', ' ', 'O', 'S', ' ', 'X')
