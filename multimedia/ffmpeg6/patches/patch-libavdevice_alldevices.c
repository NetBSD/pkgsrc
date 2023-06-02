$NetBSD: patch-libavdevice_alldevices.c,v 1.1 2023/06/02 16:44:06 wiz Exp $

Sun audio support.

--- libavdevice/alldevices.c.orig	2023-02-27 20:43:45.000000000 +0000
+++ libavdevice/alldevices.c
@@ -48,6 +48,8 @@ extern const AVInputFormat  ff_pulse_dem
 extern const FFOutputFormat ff_pulse_muxer;
 extern const FFOutputFormat ff_sdl2_muxer;
 extern const AVInputFormat  ff_sndio_demuxer;
+extern const AVInputFormat  ff_sunau_demuxer;
+extern const AVOutputFormat ff_sunau_muxer;
 extern const FFOutputFormat ff_sndio_muxer;
 extern const AVInputFormat  ff_v4l2_demuxer;
 extern const FFOutputFormat ff_v4l2_muxer;
