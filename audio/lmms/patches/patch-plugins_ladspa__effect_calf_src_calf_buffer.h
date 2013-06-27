$NetBSD: patch-plugins_ladspa__effect_calf_src_calf_buffer.h,v 1.1 2013/06/27 15:48:11 joerg Exp $

--- plugins/ladspa_effect/calf/src/calf/buffer.h.orig	2013-06-27 13:06:01.000000000 +0000
+++ plugins/ladspa_effect/calf/src/calf/buffer.h
@@ -153,7 +153,7 @@ void copy_buf(T &dest_buf, const U &src_
     typedef typename T::data_type data_type;
     data_type *dest = dest_buf.data();
     const data_type *src = src_buf.data();
-    int size = src.size();
+    int size = src->size();
     for (int i=0; i<size; i++) 
         *dest++ = (*src++) * scale + add;
 }
