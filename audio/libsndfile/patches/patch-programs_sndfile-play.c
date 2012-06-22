$NetBSD: patch-programs_sndfile-play.c,v 1.1 2012/06/22 20:31:48 adam Exp $

--- programs/sndfile-play.c.orig	2012-06-22 19:48:12.000000000 +0000
+++ programs/sndfile-play.c
@@ -58,7 +58,6 @@
 	#include 	<sys/soundcard.h>
 
 #elif (defined (__MACH__) && defined (__APPLE__))
-	#include <Carbon.h>
 	#include <CoreAudio/AudioHardware.h>
 
 #elif defined (HAVE_SNDIO_H)
