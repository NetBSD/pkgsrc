$NetBSD: patch-src_drivers_fluid_coreaudio.c,v 1.1 2012/02/27 13:24:13 adam Exp $

Fix building on Mac OS X.

--- src/drivers/fluid_coreaudio.c.orig	2012-02-27 12:48:15.000000000 +0000
+++ src/drivers/fluid_coreaudio.c
@@ -35,6 +35,7 @@
 #if COREAUDIO_SUPPORT
 #include <CoreServices/CoreServices.h>
 #include <CoreAudio/CoreAudioTypes.h>
+#include <CoreAudio/AudioHardware.h>
 #include <AudioUnit/AudioUnit.h>
 
 /*
