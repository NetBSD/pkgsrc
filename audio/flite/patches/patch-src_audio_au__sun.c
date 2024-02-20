$NetBSD: patch-src_audio_au__sun.c,v 1.1 2024/02/20 18:24:55 wiz Exp $

- Include missing header
- Use AUDIO_INITINFO for parameter initialization

--- src/audio/au_sun.c.orig	2020-08-13 00:17:09.000000000 +0000
+++ src/audio/au_sun.c
@@ -45,12 +45,18 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <sys/ioctl.h>
 #include <sys/filio.h>
 #include <sys/audioio.h>
 #include "cst_string.h"
 #include "cst_wave.h"
 #include "cst_audio.h"
 
+#ifdef __sun
+#include <stropts.h>
+#include <sys/conf.h>
+#endif
+
 static const char *sun_audio_device = "/dev/audio";
 
 cst_audiodev *audio_open_sun(int sps, int channels, cst_audiofmt fmt)
@@ -76,7 +82,7 @@ cst_audiodev *audio_open_sun(int sps, in
 	    cst_error();
 	}
     }
-    ioctl(fd,AUDIO_GETINFO,&ainfo);
+    AUDIO_INITINFO(&ainfo);
 
     switch (fmt)
     {
@@ -166,9 +172,11 @@ int audio_flush_sun(cst_audiodev *ad)
     return ioctl((int)ad->platform_data, AUDIO_DRAIN, 0);
 }
 
-/* FIXME... */
 int audio_drain_sun(cst_audiodev *ad)
 {
-    return ioctl((int)ad->platform_data, AUDIO_DRAIN, 0);
+#ifdef __sun
+    return ioctl((int)ad->platform_data, I_FLUSH, FLUSHW);
+#else
+    return ioctl((int)ad->platform_data, AUDIO_FLUSH, 0);
+#endif
 }
-
