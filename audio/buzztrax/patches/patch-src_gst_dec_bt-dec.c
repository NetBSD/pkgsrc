$NetBSD: patch-src_gst_dec_bt-dec.c,v 1.1 2019/10/16 11:18:11 nia Exp $

The macro is not autoformat friendly. If the name contains a '-', the formatter
will insert spaces and break the macro.

--- src/gst/dec/bt-dec.c.orig	2015-12-29 21:24:20.000000000 +0000
+++ src/gst/dec/bt-dec.c
@@ -953,6 +953,6 @@ plugin_init (GstPlugin * plugin)
 
 GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
     GST_VERSION_MINOR,
-    buzztrax - dec,
+    buzztraxdec,
     "Buzztrax song renderer",
     plugin_init, VERSION, "LGPL", PACKAGE_NAME, "http://www.buzztrax.org");
