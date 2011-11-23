$NetBSD: patch-ab,v 1.2 2011/11/23 23:25:36 joerg Exp $

--- akode/plugins/sun_sink/sun_sink.cpp.orig	2005-10-28 08:57:18.000000000 +0000
+++ akode/plugins/sun_sink/sun_sink.cpp
@@ -20,13 +20,15 @@
 
 #include <config.h>
 
+#include <sys/types.h>
+#include <sys/ioctl.h>
 #include <sys/audioio.h>
 
-#include <sys/ioctl.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
-#include <alloca.h>
 
 #include <audioframe.h>
 #include "sun_sink.h"
@@ -97,7 +99,7 @@ int SunSink::setAudioConfiguration(const
 {
     d->config = *config;
 
-    AUDIO_INITINFO(&d->auinfo)
+    AUDIO_INITINFO(&d->auinfo);
 
     if (ioctl(d->audio_fd, AUDIO_GETINFO, &d->auinfo) < 0)
     {
