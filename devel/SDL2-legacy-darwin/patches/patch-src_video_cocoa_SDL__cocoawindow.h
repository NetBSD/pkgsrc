$NetBSD: patch-src_video_cocoa_SDL__cocoawindow.h,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/video/cocoa/SDL_cocoawindow.h.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/video/cocoa/SDL_cocoawindow.h
@@ -35,7 +35,11 @@ typedef enum
     PENDING_OPERATION_MINIMIZE
 } PendingWindowOperation;
 
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
 @interface Cocoa_WindowListener : NSResponder <NSWindowDelegate> {
+#else
+@interface Cocoa_WindowListener : NSResponder {
+#endif
     SDL_WindowData *_data;
     BOOL observingVisible;
     BOOL wasCtrlLeft;
@@ -73,7 +77,9 @@ typedef enum
 -(void) windowDidEnterFullScreen:(NSNotification *) aNotification;
 -(void) windowWillExitFullScreen:(NSNotification *) aNotification;
 -(void) windowDidExitFullScreen:(NSNotification *) aNotification;
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
 -(NSApplicationPresentationOptions)window:(NSWindow *)window willUseFullScreenPresentationOptions:(NSApplicationPresentationOptions)proposedOptions;
+#endif
 
 /* Window event handling */
 -(void) mouseDown:(NSEvent *) theEvent;
