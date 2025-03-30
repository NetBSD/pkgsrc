$NetBSD: patch-core_libs_video_QtAVPlayer_qavstream.cpp,v 1.3 2025/03/30 07:53:02 wiz Exp $

digikam-8.6.0/core/libs/video/QtAVPlayer/qavstream.cpp: In function 'int streamRotation(const AVStream*)':
digikam-8.6.0/core/libs/video/QtAVPlayer/qavstream.cpp:100:43: error: 'round' is not a member of 'std'
  100 |     auto rotation = static_cast<int>(std::round(av_display_rotation_get(reinterpret_cast<const int32_t *>(sideData))));
      |                                           ^~~~~

https://bugs.kde.org/show_bug.cgi?id=501604

--- core/libs/video/QtAVPlayer/qavstream.cpp.orig	2025-03-15 14:01:45.000000000 +0000
+++ core/libs/video/QtAVPlayer/qavstream.cpp
@@ -9,6 +9,7 @@
 #include "qavdemuxer_p.h"
 #include "qavcodec_p.h"
 #include <QDebug>
+#include <cmath>
 
 extern "C" {
 #include <libavformat/avformat.h>
