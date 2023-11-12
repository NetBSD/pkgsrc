$NetBSD: patch-src_video_cocoa_SDL__cocoamodes.m,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/video/cocoa/SDL_cocoamodes.m.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/video/cocoa/SDL_cocoamodes.m
@@ -127,6 +127,7 @@ GetDisplayMode(_THIS, const void *modere
     }
     data->moderef = moderef;
 
+    #if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
     if (IS_SNOW_LEOPARD_OR_LATER(_this)) {
         CGDisplayModeRef vidmode = (CGDisplayModeRef) moderef;
         CFStringRef fmt = CGDisplayModeCopyPixelEncoding(vidmode);
@@ -146,6 +147,7 @@ GetDisplayMode(_THIS, const void *modere
 
         CFRelease(fmt);
     }
+    #endif
 
     #if MAC_OS_X_VERSION_MIN_REQUIRED < 1060
     if (!IS_SNOW_LEOPARD_OR_LATER(_this)) {
@@ -184,17 +186,21 @@ GetDisplayMode(_THIS, const void *modere
 static void
 Cocoa_ReleaseDisplayMode(_THIS, const void *moderef)
 {
+    #if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
     if (IS_SNOW_LEOPARD_OR_LATER(_this)) {
         CGDisplayModeRelease((CGDisplayModeRef) moderef);  /* NULL is ok */
     }
+    #endif
 }
 
 static void
 Cocoa_ReleaseDisplayModeList(_THIS, CFArrayRef modelist)
 {
+    #if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
     if (IS_SNOW_LEOPARD_OR_LATER(_this)) {
         CFRelease(modelist);  /* NULL is ok */
     }
+    #endif
 }
 
 static const char *
@@ -257,9 +263,11 @@ Cocoa_InitModes(_THIS)
                 continue;
             }
 
+            #if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
             if (IS_SNOW_LEOPARD_OR_LATER(_this)) {
                 moderef = CGDisplayCopyDisplayMode(displays[i]);
             }
+            #endif
 
             #if MAC_OS_X_VERSION_MIN_REQUIRED < 1060
             if (!IS_SNOW_LEOPARD_OR_LATER(_this)) {
@@ -319,9 +327,11 @@ Cocoa_GetDisplayModes(_THIS, SDL_VideoDi
     SDL_DisplayData *data = (SDL_DisplayData *) display->driverdata;
     CFArrayRef modes = NULL;
 
+    #if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
     if (IS_SNOW_LEOPARD_OR_LATER(_this)) {
         modes = CGDisplayCopyAllDisplayModes(data->display, NULL);
     }
+    #endif
 
     #if MAC_OS_X_VERSION_MIN_REQUIRED < 1060
     if (!IS_SNOW_LEOPARD_OR_LATER(_this)) {
@@ -337,9 +347,11 @@ Cocoa_GetDisplayModes(_THIS, SDL_VideoDi
             const void *moderef = CFArrayGetValueAtIndex(modes, i);
             SDL_DisplayMode mode;
             if (GetDisplayMode(_this, moderef, &mode)) {
+    #if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
                 if (IS_SNOW_LEOPARD_OR_LATER(_this)) {
                     CGDisplayModeRetain((CGDisplayModeRef) moderef);
                 }
+    #endif
                 SDL_AddDisplayMode(display, &mode);
             }
         }
@@ -351,9 +363,11 @@ Cocoa_GetDisplayModes(_THIS, SDL_VideoDi
 static CGError
 Cocoa_SwitchMode(_THIS, CGDirectDisplayID display, const void *mode)
 {
+    #if MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
     if (IS_SNOW_LEOPARD_OR_LATER(_this)) {
         return CGDisplaySetDisplayMode(display, (CGDisplayModeRef) mode, NULL);
     }
+    #endif
  
     #if MAC_OS_X_VERSION_MIN_REQUIRED < 1060
     if (!IS_SNOW_LEOPARD_OR_LATER(_this)) {
