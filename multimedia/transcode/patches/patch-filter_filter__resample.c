$NetBSD: patch-filter_filter__resample.c,v 1.1 2019/12/29 10:23:53 markd Exp $

Fixes building against FFmpeg version >= 4.0.0 (gentoo patch).

--- filter/filter_resample.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ filter/filter_resample.c
@@ -37,6 +37,7 @@
 #include "libtc/optstr.h"
 #include "libtc/tcavcodec.h"
 #include "libtc/tcmodule-plugin.h"
+#include <libavresample/avresample.h>
 
 
 typedef struct {
@@ -45,7 +46,7 @@ typedef struct {
 
     int bytes_per_sample;
 
-    ReSampleContext *resample_ctx;
+    AVAudioResampleContext *resample_ctx;
 } ResamplePrivateData;
 
 static const char resample_help[] = ""
