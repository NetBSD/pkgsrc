$NetBSD: patch-libao2_ao_sun.c,v 1.2 2012/06/11 13:41:13 wiz Exp $

If AUDIO_GETBUFINFO is available, use it whenever possible in preference
to AUDIO_GETINFO. This should reduce playback CPU usage.

--- libao2/ao_sun.c.orig	2011-07-24 23:55:39.000000000 +0000
+++ libao2/ao_sun.c
@@ -40,6 +40,10 @@
 #include <stropts.h>
 #endif
 
+#ifndef AUDIO_GETBUFINFO
+#define AUDIO_GETBUFINFO AUDIO_GETINFO
+#endif
+
 #include "config.h"
 #include "mixer.h"
 
@@ -162,7 +166,7 @@ static int realtime_samplecounter_availa
 	goto error;
     }
 
-    if (ioctl(fd, AUDIO_GETINFO, &info)) {
+    if (ioctl(fd, AUDIO_GETBUFINFO, &info)) {
         perror("rtsc: GETINFO1");
 	goto error;
     }
@@ -183,7 +187,7 @@ static int realtime_samplecounter_availa
 	if (usec_delay > 200000)
 	    break;
 
-	if (ioctl(fd, AUDIO_GETINFO, &info)) {
+	if (ioctl(fd, AUDIO_GETBUFINFO, &info)) {
             perror("rtsc: GETINFO2 failed");
 	    goto error;
 	}
@@ -645,7 +649,7 @@ static int get_space(void){
     }
 #endif
 
-    ioctl(audio_fd, AUDIO_GETINFO, &info);
+    ioctl(audio_fd, AUDIO_GETBUFINFO, &info);
 #if !defined (__OpenBSD__) && !defined(__NetBSD__)
     if (queued_bursts - info.play.eof > 2)
 	return 0;
@@ -681,7 +685,7 @@ static int play(void* data,int len,int f
 // return: delay in seconds between first and last sample in buffer
 static float get_delay(void){
     audio_info_t info;
-    ioctl(audio_fd, AUDIO_GETINFO, &info);
+    ioctl(audio_fd, AUDIO_GETBUFINFO, &info);
 #if defined (__OpenBSD__) || defined(__NetBSD__)
     return (float) info.play.seek/ (float)byte_per_sec ;
 #else
