$NetBSD: patch-media_libcubeb_src_cubeb__sun.c,v 1.1.2.2 2020/10/23 17:27:13 bsiegert Exp $

--- media/libcubeb/src/cubeb_sun.c.orig	2020-10-07 07:30:54.638619959 +0000
+++ media/libcubeb/src/cubeb_sun.c
@@ -744,7 +744,6 @@ static struct cubeb_ops const sun_ops = 
   .stream_get_position = sun_stream_get_position,
   .stream_get_latency = sun_stream_get_latency,
   .stream_set_volume = sun_stream_set_volume,
-  .stream_set_panning = NULL,
   .stream_get_current_device = sun_get_current_device,
   .stream_device_destroy = sun_stream_device_destroy,
   .stream_register_device_changed_callback = NULL,
