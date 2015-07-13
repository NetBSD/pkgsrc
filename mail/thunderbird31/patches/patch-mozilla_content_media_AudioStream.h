$NetBSD: patch-mozilla_content_media_AudioStream.h,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/content/media/AudioStream.h.orig	2014-07-18 00:05:12.000000000 +0000
+++ mozilla/content/media/AudioStream.h
@@ -17,6 +17,7 @@
 #include "mozilla/RefPtr.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
@@ -25,10 +26,6 @@ public:
   static void Release(cubeb_stream* aStream) { cubeb_stream_destroy(aStream); }
 };
 
-namespace soundtouch {
-class SoundTouch;
-}
-
 namespace mozilla {
 
 class AudioStream;
