$NetBSD: patch-src_youtube__video__url.cc,v 1.1 2012/09/25 11:45:11 ryoon Exp $

--- src/youtube_video_url.cc.orig	2010-04-03 20:23:31.000000000 +0000
+++ src/youtube_video_url.cc
@@ -47,7 +47,7 @@ using namespace zmm;
 #define YOUTUBE_URL_PARAMS_REGEXP   "var swfHTML.*\\;"
 #define YOUTUBE_URL_LOCATION_REGEXP "\nLocation: (http://[^\n]+)\n"
 #define YOUTUBE_URL_WATCH           "http://www.youtube.com/watch?v="
-#define YOUTUBE_URL_GET             "http://www.youtube.com/get_video?" 
+#define YOUTUBE_URL_GET             "http://www.youtube.com/get_video?asv=3&"
 #define YOUTUBE_URL_PARAM_VIDEO_ID  "video_id"
 #define YOUTUBE_URL_PARAM_T_REGEXP  ".*&t=([^&]+)&"
 #define YOUTUBE_URL_PARAM_T         "t"
