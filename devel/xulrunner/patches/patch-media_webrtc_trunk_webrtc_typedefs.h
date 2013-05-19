$NetBSD: patch-media_webrtc_trunk_webrtc_typedefs.h,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/typedefs.h.orig	2013-05-11 19:19:46.000000000 +0000
+++ media/webrtc/trunk/webrtc/typedefs.h
@@ -21,7 +21,7 @@
 // For access to standard POSIXish features, use WEBRTC_POSIX instead of a
 // more specific macro.
 #if defined(WEBRTC_MAC) || defined(WEBRTC_LINUX) || \
-    defined(WEBRTC_ANDROID)
+    defined(WEBRTC_ANDROID) || defined(WEBRTC_BSD)
 #define WEBRTC_POSIX
 #endif
 
