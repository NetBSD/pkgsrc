$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.1 2023/02/05 08:32:24 he Exp $

--- dom/media/CubebUtils.cpp.orig	2020-08-28 21:32:36.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -125,7 +125,7 @@ const char kBrandBundleURL[] = "chrome:/
 
 const char* AUDIOSTREAM_BACKEND_ID_STR[] = {
     "jack",  "pulse",       "alsa",  "audiounit", "audioqueue", "wasapi",
-    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai"};
+    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai", "sun"};
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
     ArrayLength(AUDIOSTREAM_BACKEND_ID_STR);
