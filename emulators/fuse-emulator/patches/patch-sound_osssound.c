$NetBSD: patch-sound_osssound.c,v 1.1 2017/05/26 19:35:48 adam Exp $

Use correct OSS device across platforms.

--- sound/osssound.c.orig	2007-12-21 17:43:10.000000000 +0100
+++ sound/osssound.c
@@ -52,7 +52,7 @@ int sound_lowlevel_init(const char *devi
 int frag,tmp,flags;
 
 /* select a default device if we weren't explicitly given one */
-if(device==NULL) device = "/dev/dsp";
+if(device==NULL) device = DEVOSSAUDIO;
 
 /* Open the sound device non-blocking to avoid hangs if it is being
  * used by something else, but then set it blocking again as that's what
