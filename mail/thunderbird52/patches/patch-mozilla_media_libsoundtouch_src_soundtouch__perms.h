$NetBSD: patch-mozilla_media_libsoundtouch_src_soundtouch__perms.h,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/media/libsoundtouch/src/soundtouch_perms.h.orig	2017-04-14 04:53:17.000000000 +0000
+++ mozilla/media/libsoundtouch/src/soundtouch_perms.h
@@ -12,7 +12,9 @@
 
 #pragma GCC visibility push(default)
 #include "SoundTouch.h"
+#ifndef MOZ_SYSTEM_SOUNDTOUCH
 #include "SoundTouchFactory.h"
+#endif
 #pragma GCC visibility pop
 
 #endif // MOZILLA_SOUNDTOUCH_PERMS_H
