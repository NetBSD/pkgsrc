$NetBSD: patch-stream_stream__dvdnav.c,v 1.1 2015/04/05 08:27:08 dsainty Exp $

Build against libdvdnav 5.0 API.

--- stream/stream_dvdnav.c.orig	2015-04-02 19:11:45.639187166 +1300
+++ stream/stream_dvdnav.c	2015-04-02 19:15:31.431196527 +1300
@@ -737,13 +737,13 @@
 
   format = dvdnav_audio_stream_format(priv->dvdnav, lg);
   switch(format) {
-  case DVDNAV_FORMAT_AC3:
+  case DVD_AUDIO_FORMAT_AC3:
     return index + 128;
-  case DVDNAV_FORMAT_DTS:
+  case DVD_AUDIO_FORMAT_DTS:
     return index + 136;
-  case DVDNAV_FORMAT_LPCM:
+  case DVD_AUDIO_FORMAT_LPCM:
     return index + 160;
-  case DVDNAV_FORMAT_MPEGAUDIO:
+  case DVD_AUDIO_FORMAT_MPEG2_EXT:
     return index;
   default:
     return -1;
