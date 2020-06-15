$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.4 2020/06/15 15:44:22 nia Exp $

--- dom/media/CubebUtils.cpp.orig	2020-06-02 14:07:52.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -163,7 +163,7 @@ const char kBrandBundleURL[] = "chrome:/
 
 const char* AUDIOSTREAM_BACKEND_ID_STR[] = {
     "jack",  "pulse",       "alsa",  "audiounit", "audioqueue", "wasapi",
-    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai"};
+    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai", "sun"};
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
     ArrayLength(AUDIOSTREAM_BACKEND_ID_STR);
