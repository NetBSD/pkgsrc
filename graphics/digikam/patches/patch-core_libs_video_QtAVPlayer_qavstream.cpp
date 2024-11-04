$NetBSD: patch-core_libs_video_QtAVPlayer_qavstream.cpp,v 1.1 2024/11/04 20:57:41 wiz Exp $

digikam-8.4.0/core/libs/video/QtAVPlayer/qavstream.cpp:100:43: error: 'round' is not a member of 'std'
https://invent.kde.org/graphics/digikam/-/merge_requests/318

--- core/libs/video/QtAVPlayer/qavstream.cpp.orig	2024-11-04 20:33:58.721732745 +0000
+++ core/libs/video/QtAVPlayer/qavstream.cpp
@@ -97,7 +97,7 @@ static int streamRotation(const AVStream
 #endif
     if (!sideData)
         return 0;
-    auto rotation = static_cast<int>(std::round(av_display_rotation_get(reinterpret_cast<const int32_t *>(sideData))));
+    auto rotation = static_cast<int>(round(av_display_rotation_get(reinterpret_cast<const int32_t *>(sideData))));
     if (rotation % 90 != 0)
         return 0;
     return rotation > 0 ? -rotation % 360 + 360 : -rotation % 360;
