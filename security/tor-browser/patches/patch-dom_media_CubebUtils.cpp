$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.2 2020/03/13 17:59:27 wiz Exp $

Add Sun audio support.

--- dom/media/CubebUtils.cpp.orig	2019-07-06 01:48:31.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -163,7 +163,7 @@ const char kBrandBundleURL[] = "chrome:/
 
 const char* AUDIOSTREAM_BACKEND_ID_STR[] = {
     "jack",  "pulse",       "alsa",  "audiounit", "audioqueue", "wasapi",
-    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai"};
+    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai", "sun"};
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
     ArrayLength(AUDIOSTREAM_BACKEND_ID_STR);
