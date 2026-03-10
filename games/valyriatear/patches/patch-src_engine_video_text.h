$NetBSD: patch-src_engine_video_text.h,v 1.1 2026/03/10 09:09:53 adam Exp $

Avoid conflicting typedefs with SDL2_ttf.

--- src/engine/video/text.h.orig	2026-03-10 08:43:28.184974680 +0000
+++ src/engine/video/text.h
@@ -28,7 +28,7 @@
 
 #include <map>
 
-typedef struct _TTF_Font TTF_Font;
+#include <SDL2/SDL_ttf.h>
 
 namespace vt_video
 {
