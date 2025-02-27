$NetBSD: patch-src_video_x11_SDL__x11yuv.c,v 1.1 2025/02/27 10:58:28 nia Exp $

[PATCH] SDL_x11yuv.c: fix possible use-after-free

Fixes: https://github.com/libsdl-org/SDL-1.2/issues/863

https://github.com/libsdl-org/SDL-1.2/commit/d7e00208738a0bc6af302723fe64908ac35b777b.patch

CVE-2022-34568

--- src/video/x11/SDL_x11yuv.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/x11/SDL_x11yuv.c
@@ -374,8 +374,8 @@ SDL_Overlay *X11_CreateYUVOverlay(_THIS,
 #ifdef PITCH_WORKAROUND
 		if ( hwdata->image != NULL && hwdata->image->pitches[0] != (width*bpp) ) {
 			/* Ajust overlay width according to pitch */ 
-			XFree(hwdata->image);
 			width = hwdata->image->pitches[0] / bpp;
+			XFree(hwdata->image);
 			hwdata->image = SDL_NAME(XvCreateImage)(GFX_Display, xv_port, format,
 								0, width, height);
 		}
