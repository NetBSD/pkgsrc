$NetBSD: patch-xmix.c,v 1.1 2019/07/16 10:46:45 micha Exp $

- support more OSes (is the first hunk actually correct?)
- fix void main
- remove debug printout

--- xmix.c.orig	2019-07-03 12:47:36.000000000 +0000
+++ xmix.c
@@ -77,7 +77,16 @@ to Rick! I'll call this version V2.1
 #include "square_empty.bit"
 #include "square_with_x.bit"
 
+#if defined(__linux__)
 #include <linux/soundcard.h>
+#elif defined(__NetBSD__)
+#include <sys/ioctl.h>
+#include <soundcard.h>
+#elif defined(__sun)
+#include <sys/soundcard.h>
+#else
+#include <machine/soundcard.h>
+#endif
 
 #define SOUND_FULL_SCALE 100.0
 #define MAX_SOUND_VOL 95
@@ -450,7 +459,7 @@ static void set_supported(VolumeControl 
 }
 
 
-void main (int argc, char **argv)
+int main (int argc, char **argv)
 {
   XtAppContext app_context;
   int scroll_sep, longway;
@@ -742,7 +751,7 @@ void main (int argc, char **argv)
   mic.locked = 0;
   reclvl.locked = 0;
 
-  printf("supported = 0x%x\n",supported);
+  /*printf("supported = 0x%x\n",supported);*/
   set_supported(&master,(supported & SOUND_MASK_VOLUME) != 0);
   set_supported(&bass,(supported & SOUND_MASK_BASS) != 0);
   set_supported(&treble,(supported & SOUND_MASK_TREBLE) != 0);
