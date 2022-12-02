$NetBSD: patch-src_video__dec_dav1d.c,v 1.2 2022/12/02 15:06:22 jperkin Exp $

dav1d 1.0.0 compatibility from upstream.

--- src/video_dec/dav1d.c.orig	2022-03-06 16:31:24.000000000 +0000
+++ src/video_dec/dav1d.c
@@ -544,11 +544,17 @@ static video_decoder_t *_open_plugin(vid
 
   /* multithreading */
   ncpu = xine_cpu_count();
+#if DAV1D_API_VERSION_MAJOR > 5
+  settings.n_threads = ncpu + 1;
+  xprintf(stream->xine, XINE_VERBOSITY_DEBUG, LOG_MODULE ": "
+            "Using %d threads\n", settings.n_threads);
+#else
   settings.n_frame_threads = (ncpu > 8) ? 4 : (ncpu < 2) ? 1 : ncpu/2;
   settings.n_tile_threads = MAX(1, ncpu - settings.n_frame_threads + 1);
   xprintf(stream->xine, XINE_VERBOSITY_DEBUG, LOG_MODULE ": "
             "Using %d frame threads, %d tile threads\n",
             settings.n_frame_threads, settings.n_tile_threads);
+#endif
 
   /* dri frame allocator */
   settings.allocator.cookie = this;
