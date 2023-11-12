$NetBSD: patch-src_video_cocoa_SDL__cocoaopengl.m,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/video/cocoa/SDL_cocoaopengl.m.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/video/cocoa/SDL_cocoaopengl.m
@@ -347,9 +347,11 @@ Cocoa_GL_GetDrawableSize(_THIS, SDL_Wind
 
     /* This gives us the correct viewport for a Retina-enabled view, only
      * supported on 10.7+. */
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
     if ([contentView respondsToSelector:@selector(convertRectToBacking:)]) {
         viewport = [contentView convertRectToBacking:viewport];
     }
+#endif
 
     if (w) {
         *w = viewport.size.width;
