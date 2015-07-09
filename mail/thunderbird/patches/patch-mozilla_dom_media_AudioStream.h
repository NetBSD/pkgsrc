$NetBSD: patch-mozilla_dom_media_AudioStream.h,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/dom/media/AudioStream.h.orig	2015-06-08 17:49:28.000000000 +0000
+++ mozilla/dom/media/AudioStream.h
@@ -17,7 +17,7 @@
 #include "CubebUtils.h"
 
 namespace soundtouch {
-class SoundTouch;
+class MOZ_IMPORT_API SoundTouch;
 }
 
 namespace mozilla {
