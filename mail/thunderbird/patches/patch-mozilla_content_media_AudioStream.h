$NetBSD: patch-mozilla_content_media_AudioStream.h,v 1.1 2014/07/27 20:04:59 ryoon Exp $

--- mozilla/content/media/AudioStream.h.orig	2014-07-18 00:05:12.000000000 +0000
+++ mozilla/content/media/AudioStream.h
@@ -17,6 +17,7 @@
 #include "mozilla/RefPtr.h"
 
 #include "cubeb/cubeb.h"
+#include "soundtouch/SoundTouch.h"
 
 template <>
 class nsAutoRefTraits<cubeb_stream> : public nsPointerRefTraits<cubeb_stream>
@@ -26,7 +27,7 @@ public:
 };
 
 namespace soundtouch {
-class SoundTouch;
+class MOZ_IMPORT_API SoundTouch;
 }
 
 namespace mozilla {
