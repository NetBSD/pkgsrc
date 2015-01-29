$NetBSD: patch-src_video_wscons_SDL__wsconsevents__c.h,v 1.1 2015/01/29 01:56:23 jmcneill Exp $

--- src/video/wscons/SDL_wsconsevents_c.h.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/wscons/SDL_wsconsevents_c.h
@@ -25,6 +25,8 @@
 
 int WSCONS_InitKeyboard(_THIS);
 void WSCONS_ReleaseKeyboard(_THIS);
+int WSCONS_InitMouse(_THIS);
+void WSCONS_ReleaseMouse(_THIS);
 
 /* Variables and functions exported by SDL_sysevents.c to other parts 
    of the native video subsystem (SDL_sysvideo.c)
