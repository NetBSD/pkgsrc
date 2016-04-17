$NetBSD: patch-mozilla_dom_media_gstreamer_GStreamerAllocator.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/dom/media/gstreamer/GStreamerAllocator.cpp.orig	2015-06-08 17:49:28.000000000 +0000
+++ mozilla/dom/media/gstreamer/GStreamerAllocator.cpp
@@ -51,7 +51,6 @@ typedef struct
 #pragma GCC diagnostic ignored "-Wunused-function"
 G_DEFINE_TYPE(MozGfxMemoryAllocator, moz_gfx_memory_allocator, GST_TYPE_ALLOCATOR);
 G_DEFINE_TYPE(MozGfxBufferPool, moz_gfx_buffer_pool, GST_TYPE_VIDEO_BUFFER_POOL);
-#pragma GCC diagnostic pop
 
 void
 moz_gfx_memory_reset(MozGfxMemory *mem)
