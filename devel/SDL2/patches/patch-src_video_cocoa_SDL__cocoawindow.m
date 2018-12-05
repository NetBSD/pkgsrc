$NetBSD: patch-src_video_cocoa_SDL__cocoawindow.m,v 1.1 2018/12/05 10:46:15 bsiegert Exp $

# HG changeset patch
# User Ryan C. Gordon <icculus@icculus.org>
# Date 1538007032 14400
# Node ID 55489adbb75c8eb7c7719a3f9c85a15d06df2f27
# Parent  21c0605222581aa820dbb19db987c5dc0d497239
cocoa: Force an OpenGL context update when the window becomes key.

Fixes missing rendering on macOS 10.14 ("Mojave").

Fixes Bugzilla #4272.

--- src/video/cocoa/SDL_cocoawindow.m.orig	2018-10-31 15:07:22.000000000 +0000
+++ src/video/cocoa/SDL_cocoawindow.m
@@ -632,6 +632,8 @@ SetWindowStyle(SDL_Window * window, NSUI
     const unsigned int newflags = [NSEvent modifierFlags] & NSEventModifierFlagCapsLock;
     _data->videodata->modifierFlags = (_data->videodata->modifierFlags & ~NSEventModifierFlagCapsLock) | newflags;
     SDL_ToggleModState(KMOD_CAPS, newflags != 0);
+
+    ScheduleContextUpdates(_data);
 }
 
 - (void)windowDidResignKey:(NSNotification *)aNotification
