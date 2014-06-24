$NetBSD: patch-libvo_vo__corevideo.h,v 1.1 2014/06/24 12:03:42 wiz Exp $

Apparently Apple have moved things around. Explicitly include the GL headers
for Mavericks SDK.

--- libvo/vo_corevideo.h.orig	2014-06-24 11:24:53.000000000 +0000
+++ libvo/vo_corevideo.h
@@ -26,6 +26,9 @@
 #import <Cocoa/Cocoa.h>
 #import <QuartzCore/QuartzCore.h>
 #import <Carbon/Carbon.h>
+#if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
+#import <OpenGL/gl.h>
+#endif
 
 // MPlayer OS X VO Protocol
 @protocol MPlayerOSXVOProto
