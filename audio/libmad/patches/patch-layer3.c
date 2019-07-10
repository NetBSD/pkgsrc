$NetBSD: patch-layer3.c,v 1.1 2019/07/10 20:01:57 nia Exp $

Fixes for CVE-2017-8372, CVE-2017-8373, CVE-2017-8374.

From Kurt Roeckx / Debian.

--- layer3.c.orig	2019-07-10 19:49:26.252016169 +0000
+++ layer3.c
@@ -2688,6 +2688,11 @@ int mad_layer_III(struct mad_stream *str
     next_md_begin = 0;
 
   md_len = si.main_data_begin + frame_space - next_md_begin;
+  if (md_len + MAD_BUFFER_GUARD > MAD_BUFFER_MDLEN) {
+    stream->error = MAD_ERROR_LOSTSYNC;
+    stream->sync = 0;
+    return -1;
+  }
 
   frame_used = 0;
 
@@ -2705,8 +2710,11 @@ int mad_layer_III(struct mad_stream *str
       }
     }
     else {
-      mad_bit_init(&ptr,
-		   *stream->main_data + stream->md_len - si.main_data_begin);
+      memmove(stream->main_data,
+	*stream->main_data + stream->md_len - si.main_data_begin,
+	si.main_data_begin);
+      stream->md_len = si.main_data_begin;
+      mad_bit_init(&ptr, *stream->main_data);
 
       if (md_len > si.main_data_begin) {
 	assert(stream->md_len + md_len -
