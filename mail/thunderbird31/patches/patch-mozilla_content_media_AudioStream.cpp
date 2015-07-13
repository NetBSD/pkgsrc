$NetBSD: patch-mozilla_content_media_AudioStream.cpp,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/content/media/AudioStream.cpp.orig	2014-07-18 00:05:12.000000000 +0000
+++ mozilla/content/media/AudioStream.cpp
@@ -13,7 +13,6 @@
 #include "mozilla/Mutex.h"
 #include <algorithm>
 #include "mozilla/Preferences.h"
-#include "soundtouch/SoundTouch.h"
 #include "Latency.h"
 
 namespace mozilla {
