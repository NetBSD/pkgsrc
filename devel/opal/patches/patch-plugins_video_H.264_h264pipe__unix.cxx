$NetBSD: patch-plugins_video_H.264_h264pipe__unix.cxx,v 1.1 2013/10/15 14:42:10 joerg Exp $

--- plugins/video/H.264/h264pipe_unix.cxx.orig	2013-10-14 17:21:08.000000000 +0000
+++ plugins/video/H.264/h264pipe_unix.cxx
@@ -27,6 +27,7 @@
 
 #include <stdlib.h>
 #include <errno.h>
+#include <unistd.h>
 #include <sys/stat.h>
 #include "trace.h"
 #include "rtpframe.h"
