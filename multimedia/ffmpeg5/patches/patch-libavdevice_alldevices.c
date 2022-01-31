$NetBSD: patch-libavdevice_alldevices.c,v 1.1 2022/01/31 23:16:41 ryoon Exp $

Sun audio support.

--- libavdevice/alldevices.c.orig	2022-01-14 18:45:40.000000000 +0000
+++ libavdevice/alldevices.c
@@ -48,6 +48,8 @@ extern const AVOutputFormat ff_pulse_mux
 extern const AVOutputFormat ff_sdl2_muxer;
 extern const AVInputFormat  ff_sndio_demuxer;
 extern const AVOutputFormat ff_sndio_muxer;
+extern const AVInputFormat  ff_sunau_demuxer;
+extern const AVOutputFormat ff_sunau_muxer;
 extern const AVInputFormat  ff_v4l2_demuxer;
 extern const AVOutputFormat ff_v4l2_muxer;
 extern const AVInputFormat  ff_vfwcap_demuxer;
