$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.1 2018/12/16 08:12:15 ryoon Exp $

--- dom/media/CubebUtils.cpp.orig	2018-12-04 23:11:46.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -152,7 +152,8 @@ const char* AUDIOSTREAM_BACKEND_ID_STR[]
   "sndio",
   "opensl",
   "audiotrack",
-  "kai"
+  "kai",
+  "oss",
 };
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
