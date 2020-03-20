$NetBSD: patch-libavdevice_alldevices.c,v 1.1 2020/03/20 21:19:54 nia Exp $

Sun audio support.

--- libavdevice/alldevices.c.orig	2019-12-31 21:35:24.000000000 +0000
+++ libavdevice/alldevices.c
@@ -49,6 +49,8 @@ extern AVOutputFormat ff_pulse_muxer;
 extern AVOutputFormat ff_sdl2_muxer;
 extern AVInputFormat  ff_sndio_demuxer;
 extern AVOutputFormat ff_sndio_muxer;
+extern AVInputFormat  ff_sunau_demuxer;
+extern AVOutputFormat ff_sunau_muxer;
 extern AVInputFormat  ff_v4l2_demuxer;
 extern AVOutputFormat ff_v4l2_muxer;
 extern AVInputFormat  ff_vfwcap_demuxer;
