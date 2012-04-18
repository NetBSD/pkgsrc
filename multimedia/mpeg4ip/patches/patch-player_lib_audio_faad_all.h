$NetBSD: patch-player_lib_audio_faad_all.h,v 1.1 2012/04/18 00:09:44 joerg Exp $

config.c needs two scratch channels.

--- player/lib/audio/faad/all.h.orig	2012-04-17 21:37:48.000000000 +0000
+++ player/lib/audio/faad/all.h
@@ -59,7 +59,7 @@ enum
     BChans	= 15,	/* back channels: left surround, right surround */
     BCenter	= 1,	/* 1 if decoder has back center channel */
     LChans	= 1,	/* LFE channels */
-    XChans	= 1,	/* scratch space for parsing unused channels */  
+    XChans	= 2,	/* scratch space for parsing unused channels */  
 #else
     FChans	= 3,	/* front channels: left, center, right */
     FCenter	= 0,	/* 1 if decoder has front center channel */
@@ -67,7 +67,7 @@ enum
     BChans	= 1,	/* back channels: left surround, right surround */
     BCenter	= 0,	/* 1 if decoder has back center channel */
     LChans	= 1,	/* LFE channels */
-    XChans	= 1,	/* scratch space for parsing unused channels */  
+    XChans	= 2,	/* scratch space for parsing unused channels */  
 #endif
     
     Chans	= FChans + SChans + BChans + LChans + XChans
