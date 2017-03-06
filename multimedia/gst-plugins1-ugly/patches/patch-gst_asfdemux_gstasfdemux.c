$NetBSD: patch-gst_asfdemux_gstasfdemux.c,v 1.1 2017/03/06 08:01:40 snj Exp $

CVE-2017-5847

https://github.com/GStreamer/gst-plugins-ugly/commit/d21017b52a585f145e8d62781bcc1c5fefc7ee37

--- gst/asfdemux/gstasfdemux.c.orig	2017-01-30 05:41:35.000000000 -0800
+++ gst/asfdemux/gstasfdemux.c	2017-03-05 23:45:12.000000000 -0800
@@ -3439,7 +3439,12 @@ gst_asf_demux_process_ext_content_desc (
           break;
         }
         case ASF_DEMUX_DATA_TYPE_DWORD:{
-          guint uint_val = GST_READ_UINT32_LE (value);
+          guint uint_val;
+
+          if (value_len < 4)
+            break;
+
+          uint_val = GST_READ_UINT32_LE (value);
 
           /* this is the track number */
           g_value_init (&tag_value, G_TYPE_UINT);
@@ -3453,7 +3458,12 @@ gst_asf_demux_process_ext_content_desc (
         }
           /* Detect 3D */
         case ASF_DEMUX_DATA_TYPE_BOOL:{
-          gboolean bool_val = GST_READ_UINT32_LE (value);
+          gboolean bool_val;
+
+          if (value_len < 4)
+            break;
+
+          bool_val = GST_READ_UINT32_LE (value);
 
           if (strncmp ("Stereoscopic", name_utf8, strlen (name_utf8)) == 0) {
             if (bool_val) {
