$NetBSD: patch-libmp3lame_lame.c,v 1.3 2017/12/04 08:20:37 he Exp $

Add patch to check against invalid input sample rate.
Should fix CVE-2015-9099.  Ref.
https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=775959

--- libmp3lame/lame.c.orig	2017-10-10 19:08:39.000000000 +0000
+++ libmp3lame/lame.c
@@ -801,6 +801,12 @@ lame_init_params(lame_global_flags * gfp
             gfp->samplerate_out * 16 * cfg->channels_out / (1.e3 * gfp->VBR_mean_bitrate_kbps);
     }
 
+    if (gfp->samplerate_in < 0) {
+	freegfc(gfc);
+	gfp->internal_flags = NULL;
+	return -1;
+    }
+
     cfg->disable_reservoir = gfp->disable_reservoir;
     cfg->lowpassfreq = gfp->lowpassfreq;
     cfg->highpassfreq = gfp->highpassfreq;
