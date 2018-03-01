$NetBSD: patch-ext_x264_gstx264enc.c,v 1.1 2018/03/01 22:31:08 snj Exp $

Fix build with newer libx264.  From:
https://cgit.freedesktop.org/gstreamer/gst-plugins-ugly/commit/?id=83c38dc44622611c1f67dd26e4cb383c5aef90f6

--- ext/x264/gstx264enc.c.orig	2017-07-25 01:26:28.000000000 -0700
+++ ext/x264/gstx264enc.c	2018-03-01 14:16:58.880753252 -0800
@@ -117,7 +117,9 @@ struct _GstX264EncVTable
 {
   GModule *module;
 
+#if X264_BUILD < 153
   const int *x264_bit_depth;
+#endif
   const int *x264_chroma_format;
   void (*x264_encoder_close) (x264_t *);
   int (*x264_encoder_delayed_frames) (x264_t *);
@@ -170,8 +172,9 @@ load_x264 (const gchar * filename)
         "' from '%s'. Incompatible version?", filename);
     goto error;
   }
-
+#if X264_BUILD < 153
   LOAD_SYMBOL (x264_bit_depth);
+#endif
   LOAD_SYMBOL (x264_chroma_format);
   LOAD_SYMBOL (x264_encoder_close);
   LOAD_SYMBOL (x264_encoder_delayed_frames);
@@ -288,6 +291,7 @@ gst_x264_enc_add_x264_chroma_format (Gst
   return ret;
 }
 
+#if X264_BUILD < 153
 static gboolean
 load_x264_libraries (void)
 {
@@ -326,6 +330,33 @@ load_x264_libraries (void)
   return TRUE;
 }
 
+#else /* X264_BUILD >= 153 */
+
+static gboolean
+load_x264_libraries (void)
+{
+#if X264_BIT_DEPTH == 0         /* all */
+  vtable_8bit = &default_vtable;
+  vtable_10bit = &default_vtable;
+#elif X264_BIT_DEPTH == 8
+  vtable_8bit = &default_vtable;
+#elif X264_BIT_DEPTH == 10
+  vtable_10bit = &default_vtable;
+#else
+#error "unexpected X264_BIT_DEPTH value"
+#endif
+
+#ifdef HAVE_X264_ADDITIONAL_LIBRARIES
+  GST_WARNING ("Ignoring configured additional libraries %s, using libx264 "
+      "version enabled for multiple bit depths",
+      HAVE_X264_ADDITIONAL_LIBRARIES);
+#endif
+
+  return TRUE;
+}
+
+#endif
+
 enum
 {
   ARG_0,
@@ -2897,7 +2928,9 @@ plugin_init (GstPlugin * plugin)
    * if needed. We can't initialize statically because these values are not
    * constant on Windows. */
   default_vtable.module = NULL;
+#if X264_BUILD < 153
   default_vtable.x264_bit_depth = &x264_bit_depth;
+#endif
   default_vtable.x264_chroma_format = &x264_chroma_format;
   default_vtable.x264_encoder_close = x264_encoder_close;
   default_vtable.x264_encoder_delayed_frames = x264_encoder_delayed_frames;
