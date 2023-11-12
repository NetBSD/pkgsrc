$NetBSD: patch-src_video_cocoa_SDL__cocoaclipboard.m,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/video/cocoa/SDL_cocoaclipboard.m.orig	2014-03-16 02:31:45.000000000 +0000
+++ src/video/cocoa/SDL_cocoaclipboard.m
@@ -30,11 +30,15 @@ GetTextFormat(_THIS)
 {
     SDL_VideoData *data = (SDL_VideoData *) _this->driverdata;
 
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
     if (data->osversion >= 0x1060) {
         return NSPasteboardTypeString;
     } else {
+#endif
         return NSStringPboardType;
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
     }
+#endif
 }
 
 int
