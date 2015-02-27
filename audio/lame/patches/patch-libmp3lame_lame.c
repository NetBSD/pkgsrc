$NetBSD: patch-libmp3lame_lame.c,v 1.1 2015/02/27 19:49:16 snj Exp $

https://bugs.debian.org/778703

--- libmp3lame/lame.c.orig	2011-10-18 14:51:20.000000000 -0700
+++ libmp3lame/lame.c	2015-02-27 11:06:06.000000000 -0800
@@ -822,6 +822,12 @@ lame_init_params(lame_global_flags * gfp
     }
 #endif
 
+    if (gfp->samplerate_in < 0 || gfp->num_channels < 0) {
+        freegfc(gfc);
+        gfp->internal_flags = NULL;
+        return -1;
+    }
+
     cfg->disable_reservoir = gfp->disable_reservoir;
     cfg->lowpassfreq = gfp->lowpassfreq;
     cfg->highpassfreq = gfp->highpassfreq;
