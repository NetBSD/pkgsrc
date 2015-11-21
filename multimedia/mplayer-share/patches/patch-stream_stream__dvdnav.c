$NetBSD: patch-stream_stream__dvdnav.c,v 1.2 2015/11/21 09:47:23 leot Exp $

Build against libdvdnav 5.0 API.

--- stream/stream_dvdnav.c.orig	2014-10-24 23:01:02.000000000 +0000
+++ stream/stream_dvdnav.c
@@ -721,13 +721,13 @@ static int mp_dvdnav_get_aid_from_format
 
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
