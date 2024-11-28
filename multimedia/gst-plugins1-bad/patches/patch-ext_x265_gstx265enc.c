$NetBSD: patch-ext_x265_gstx265enc.c,v 1.1 2024/11/28 10:29:18 prlw1 Exp $

upstream commit ee3802cf71b386194e2a6318765e0547b37f52c8

  x265: Allow building with x265-4.1
    
  In x265-4.1 masteringDisplayColorVolume is changed from a pointer to a
  character array embedded in struct x265_param.
    
  https://gitlab.freedesktop.org/gstreamer/gstreamer/-/merge_requests/7968

--- ext/x265/gstx265enc.c.orig	2024-10-30 20:33:30.000000000 +0000
+++ ext/x265/gstx265enc.c
@@ -948,8 +948,13 @@ gst_x265_enc_init_encoder_locked (GstX26
        * HEVC uses gbr order
        * See spec D.3.28 display_primaries_x and display_primaries_y
        */
-      encoder->x265param.masteringDisplayColorVolume =
-          g_strdup_printf ("G(%hu,%hu)B(%hu,%hu)R(%hu,%hu)WP(%hu,%hu)L(%u,%u)",
+#if X265_BUILD < 214
+      encoder->x265param.masteringDisplayColorVolume = g_strdup_printf (
+#else
+      snprintf (encoder->x265param.masteringDisplayColorVolume,
+          X265_MAX_STRING_SIZE,
+#endif
+          "G(%hu,%hu)B(%hu,%hu)R(%hu,%hu)WP(%hu,%hu)L(%u,%u)",
           minfo.display_primaries[1].x, minfo.display_primaries[1].y,
           minfo.display_primaries[2].x, minfo.display_primaries[2].y,
           minfo.display_primaries[0].x, minfo.display_primaries[0].y,
