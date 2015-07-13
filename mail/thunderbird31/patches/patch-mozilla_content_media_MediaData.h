$NetBSD: patch-mozilla_content_media_MediaData.h,v 1.1 2015/07/13 17:49:26 ryoon Exp $

Fix build with gcc 4.9 
https://bugzilla.mozilla.org/show_bug.cgi?id=999496 

--- mozilla/content/media/MediaData.h.orig	2014-07-18 00:05:12.000000000 +0000
+++ mozilla/content/media/MediaData.h
@@ -80,13 +80,7 @@ public:
     MOZ_COUNT_DTOR(AudioData);
   }
 
-  size_t SizeOfIncludingThis(MallocSizeOf aMallocSizeOf) const {
-    size_t size = aMallocSizeOf(this) + aMallocSizeOf(mAudioData);
-    if (mAudioBuffer) {
-      size += mAudioBuffer->SizeOfIncludingThis(aMallocSizeOf);
-    }
-    return size;
-  }
+  size_t SizeOfIncludingThis(MallocSizeOf aMallocSizeOf) const;
 
   // If mAudioBuffer is null, creates it from mAudioData.
   void EnsureAudioBuffer();
