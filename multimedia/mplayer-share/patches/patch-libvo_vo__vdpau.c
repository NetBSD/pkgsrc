$NetBSD: patch-libvo_vo__vdpau.c,v 1.1.2.2 2017/11/04 18:02:39 bsiegert Exp $

* Include vdpau_x11.h explicitly to fix build of multimedia/mplayer
  with ffmpeg 3.4

--- libvo/vo_vdpau.c.orig	2016-02-14 22:28:20.000000000 +0000
+++ libvo/vo_vdpau.c
@@ -51,6 +51,7 @@
 #include "subopt-helper.h"
 
 #include "libavcodec/vdpau.h"
+#include <vdpau/vdpau_x11.h>
 
 #include "libavutil/common.h"
 #include "libavutil/mathematics.h"
