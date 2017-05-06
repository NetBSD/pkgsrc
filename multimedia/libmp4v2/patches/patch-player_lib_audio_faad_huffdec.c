$NetBSD: patch-player_lib_audio_faad_huffdec.c,v 1.1 2017/05/06 18:12:00 maya Exp $

correct misleading indentation (not changing behaviour)

--- player/lib/audio/faad/huffdec.c.orig	2003-02-18 18:51:31.000000000 +0000
+++ player/lib/audio/faad/huffdec.c
@@ -369,7 +369,8 @@ static int getmask(faacDecHandle hDecode
         for(b = 0; b < info->nsbk; b = *group++)
             for(i = 0; i < info->sfb_per_sbk[b]; i ++)
                 *mask++ = 1;
-            return 2;
+
+        return 2;
     }
 
     /* otherwise get mask */
