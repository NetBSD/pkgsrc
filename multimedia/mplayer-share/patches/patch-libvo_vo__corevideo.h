$NetBSD: patch-libvo_vo__corevideo.h,v 1.2 2015/11/21 09:47:23 leot Exp $

Apparently Apple have moved things around. Explicitly include the GL headers
for Mavericks SDK.

--- libvo/vo_corevideo.h.orig	2013-10-30 18:51:33.000000000 +0000
+++ libvo/vo_corevideo.h
@@ -26,7 +26,9 @@
 #import <Cocoa/Cocoa.h>
 #import <QuartzCore/QuartzCore.h>
 #import <Carbon/Carbon.h>
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
 #import <OpenGL/gl.h>
+#endif
 #import "osx_objc_common.h"
 
 // MPlayer OS X VO Protocol
