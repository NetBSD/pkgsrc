$NetBSD: patch-src_video_cocoa_SDL__cocoawindow.m,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/video/cocoa/SDL_cocoawindow.m.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/video/cocoa/SDL_cocoawindow.m
@@ -23,7 +23,9 @@
 #if SDL_VIDEO_DRIVER_COCOA
 
 #if MAC_OS_X_VERSION_MAX_ALLOWED < 1070
+#if 0
 # error SDL for Mac OS X must be built with a 10.7 SDK or above.
+#endif
 #endif /* MAC_OS_X_VERSION_MAX_ALLOWED < 1070 */
 
 #include "SDL_syswm.h"
@@ -100,7 +102,14 @@ ScheduleContextUpdates(SDL_WindowData *d
     NSOpenGLContext *currentContext = [NSOpenGLContext currentContext];
     NSMutableArray *contexts = data->nscontexts;
     @synchronized (contexts) {
+#if defined(MAC_OS_X_VERSION_10_5)
         for (SDLOpenGLContext *context in contexts) {
+#else
+        /* old way to iterate */
+        int i;
+        for (i = 0; i < [contexts count]; i++) {
+            SDLOpenGLContext *context = [contexts objectAtIndex:i];
+#endif
             if (context == currentContext) {
                 [context update];
             } else {
@@ -190,10 +199,12 @@ SetWindowStyle(SDL_Window * window, unsi
         [center addObserver:self selector:@selector(windowDidDeminiaturize:) name:NSWindowDidDeminiaturizeNotification object:window];
         [center addObserver:self selector:@selector(windowDidBecomeKey:) name:NSWindowDidBecomeKeyNotification object:window];
         [center addObserver:self selector:@selector(windowDidResignKey:) name:NSWindowDidResignKeyNotification object:window];
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
         [center addObserver:self selector:@selector(windowWillEnterFullScreen:) name:NSWindowWillEnterFullScreenNotification object:window];
         [center addObserver:self selector:@selector(windowDidEnterFullScreen:) name:NSWindowDidEnterFullScreenNotification object:window];
         [center addObserver:self selector:@selector(windowWillExitFullScreen:) name:NSWindowWillExitFullScreenNotification object:window];
         [center addObserver:self selector:@selector(windowDidExitFullScreen:) name:NSWindowDidExitFullScreenNotification object:window];
+#endif
     } else {
         [window setDelegate:self];
     }
@@ -212,9 +223,11 @@ SetWindowStyle(SDL_Window * window, unsi
 
     [view setNextResponder:self];
 
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
     if ([view respondsToSelector:@selector(setAcceptsTouchEvents:)]) {
         [view setAcceptsTouchEvents:YES];
     }
+#endif
 }
 
 - (void)observeValueForKeyPath:(NSString *)keyPath
@@ -282,7 +295,9 @@ SetWindowStyle(SDL_Window * window, unsi
     inFullscreenTransition = YES;
 
     /* you need to be FullScreenPrimary, or toggleFullScreen doesn't work. Unset it again in windowDidExitFullScreen. */
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
     [nswindow setCollectionBehavior:NSWindowCollectionBehaviorFullScreenPrimary];
+#endif
     [nswindow performSelectorOnMainThread: @selector(toggleFullScreen:) withObject:nswindow waitUntilDone:NO];
     return YES;
 }
@@ -319,10 +334,12 @@ SetWindowStyle(SDL_Window * window, unsi
         [center removeObserver:self name:NSWindowDidDeminiaturizeNotification object:window];
         [center removeObserver:self name:NSWindowDidBecomeKeyNotification object:window];
         [center removeObserver:self name:NSWindowDidResignKeyNotification object:window];
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
         [center removeObserver:self name:NSWindowWillEnterFullScreenNotification object:window];
         [center removeObserver:self name:NSWindowDidEnterFullScreenNotification object:window];
         [center removeObserver:self name:NSWindowWillExitFullScreenNotification object:window];
         [center removeObserver:self name:NSWindowDidExitFullScreenNotification object:window];
+#endif
     } else {
         [window setDelegate:nil];
     }
@@ -346,8 +363,14 @@ SetWindowStyle(SDL_Window * window, unsi
        !!! FIXME:   http://bugzilla.libsdl.org/show_bug.cgi?id=1825
     */
     windows = [NSApp orderedWindows];
-    for (NSWindow *win in windows)
-    {
+#if defined(MAC_OS_X_VERSION_10_5)
+    for (NSWindow *win in windows) {
+#else
+    /* old way to iterate */
+    int i;
+    for (i = 0; i < [windows count]; i++) {
+        NSWindow *win = [windows objectAtIndex:i];
+#endif
         if (win == window) {
             continue;
         }
@@ -597,12 +620,14 @@ SetWindowStyle(SDL_Window * window, unsi
         [nswindow miniaturize:nil];
     } else {
         /* Adjust the fullscreen toggle button and readd menu now that we're here. */
+#if MAC_OS_X_VERSION_MIN_REQUIRED > 1070
         if (window->flags & SDL_WINDOW_RESIZABLE) {
             /* resizable windows are Spaces-friendly: they get the "go fullscreen" toggle button on their titlebar. */
             [nswindow setCollectionBehavior:NSWindowCollectionBehaviorFullScreenPrimary];
         } else {
             [nswindow setCollectionBehavior:NSWindowCollectionBehaviorManaged];
         }
+#endif
         [NSMenu setMenuBarVisible:YES];
 
         pendingWindowOperation = PENDING_OPERATION_NONE;
@@ -620,6 +645,7 @@ SetWindowStyle(SDL_Window * window, unsi
     }
 }
 
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
 -(NSApplicationPresentationOptions)window:(NSWindow *)window willUseFullScreenPresentationOptions:(NSApplicationPresentationOptions)proposedOptions
 {
     if ((_data->window->flags & SDL_WINDOW_FULLSCREEN_DESKTOP) == SDL_WINDOW_FULLSCREEN_DESKTOP) {
@@ -628,6 +654,7 @@ SetWindowStyle(SDL_Window * window, unsi
         return proposedOptions;
     }
 }
+#endif
 
 
 /* We'll respond to key events by doing nothing so we don't beep.
@@ -822,6 +849,7 @@ SetWindowStyle(SDL_Window * window, unsi
     [self handleTouches:COCOA_TOUCH_CANCELLED withEvent:theEvent];
 }
 
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
 - (void)handleTouches:(cocoaTouchType)type withEvent:(NSEvent *)event
 {
     NSSet *touches = 0;
@@ -875,6 +903,7 @@ SetWindowStyle(SDL_Window * window, unsi
         touch = (NSTouch*)[enumerator nextObject];
     }
 }
+#endif
 
 @end
 
@@ -1040,6 +1069,7 @@ Cocoa_CreateWindow(_THIS, SDL_Window * w
     [nswindow setBackgroundColor:[NSColor blackColor]];
 
     if (videodata->allow_spaces) {
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
         SDL_assert(videodata->osversion >= 0x1070);
         SDL_assert([nswindow respondsToSelector:@selector(toggleFullScreen:)]);
         /* we put FULLSCREEN_DESKTOP windows in their own Space, without a toggle button or menubar, later */
@@ -1047,6 +1077,7 @@ Cocoa_CreateWindow(_THIS, SDL_Window * w
             /* resizable windows are Spaces-friendly: they get the "go fullscreen" toggle button on their titlebar. */
             [nswindow setCollectionBehavior:NSWindowCollectionBehaviorFullScreenPrimary];
         }
+#endif
     }
 
     /* Create a default view for this window */
@@ -1490,7 +1521,14 @@ Cocoa_DestroyWindow(_THIS, SDL_Window * 
         }
 
         NSArray *contexts = [[data->nscontexts copy] autorelease];
+#if defined(MAC_OS_X_VERSION_10_5)
         for (SDLOpenGLContext *context in contexts) {
+#else
+        /* old way to iterate */
+        int i;
+        for (i = 0; i < [contexts count]; i++) {
+            SDLOpenGLContext *context = [contexts objectAtIndex:i];
+#endif
             /* Calling setWindow:NULL causes the context to remove itself from the context list. */            
             [context setWindow:NULL];
         }
