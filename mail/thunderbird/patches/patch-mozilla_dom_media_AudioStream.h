$NetBSD: patch-mozilla_dom_media_AudioStream.h,v 1.3 2017/04/27 13:32:40 ryoon Exp $

--- mozilla/dom/media/AudioStream.h.orig	2017-04-14 04:53:05.000000000 +0000
+++ mozilla/dom/media/AudioStream.h
@@ -16,7 +16,11 @@
 #include "mozilla/TimeStamp.h"
 #include "mozilla/UniquePtr.h"
 #include "CubebUtils.h"
+#ifdef MOZ_SYSTEM_SOUNDTOUCH
+#include "soundtouch/SoundTouch.h"
+#else
 #include "soundtouch/SoundTouchFactory.h"
+#endif
 
 namespace mozilla {
 
@@ -281,7 +285,11 @@ private:
   uint32_t mChannels;
   uint32_t mOutChannels;
   AudioClock mAudioClock;
+#ifdef MOZ_SYSTEM_SOUNDTOUCH
+  nsAutoPtr<soundtouch::SoundTouch> mTimeStretcher;
+#else
   soundtouch::SoundTouch* mTimeStretcher;
+#endif
 
   // Output file for dumping audio
   FILE* mDumpFile;
