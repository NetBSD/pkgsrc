$NetBSD: patch-src_video_cocoa_SDL__cocoakeyboard.m,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/video/cocoa/SDL_cocoakeyboard.m.orig	2014-03-16 02:31:45.000000000 +0000
+++ src/video/cocoa/SDL_cocoakeyboard.m
@@ -426,6 +426,7 @@ HandleModifiers(_THIS, unsigned short sc
 static void
 UpdateKeymap(SDL_VideoData *data)
 {
+#if defined(MAC_OS_X_VERSION_10_5)
     TISInputSourceRef key_layout;
     const void *chr_data;
     int i;
@@ -483,6 +484,7 @@ UpdateKeymap(SDL_VideoData *data)
 
 cleanup:
     CFRelease(key_layout);
+#endif
 }
 
 void
