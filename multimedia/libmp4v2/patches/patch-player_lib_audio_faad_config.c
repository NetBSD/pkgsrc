$NetBSD: patch-player_lib_audio_faad_config.c,v 1.1 2017/05/06 18:12:00 maya Exp $

if 0 possible out of bounds write
Our scratch space is one channel wide, don't treat it
like two if we're doing stereo.

--- player/lib/audio/faad/config.c.orig	2003-04-09 00:44:38.000000000 +0000
+++ player/lib/audio/faad/config.c
@@ -628,15 +628,18 @@ static int ch_index(MC_Info *mip, int cp
      */
     if (XChans > 0) {
     ch = Chans - XChans;    /* left scratch channel */
-    mip->ch_info[ch].cpe = cpe;
+    mip->ch_info[ch].cpe = 0;
     mip->ch_info[ch].ch_is_left = 1;
     mip->ch_info[ch].widx = ch;
+#if 0 /* Possible out of bound write. we only have one scratch channel */
     if (cpe) {
         mip->ch_info[ch].paired_ch = ch+1;
         mip->ch_info[ch+1].ch_is_left = 0;
         mip->ch_info[ch+1].paired_ch = ch;
     }
+#endif
     }
+    /* XXX Below code never happens, XChans seems to always be 1. Assert? */
     else {
     ch = -1;        /* error, no scratch space */
     }
