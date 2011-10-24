$NetBSD: patch-libao2_ao_sun.c,v 1.1 2011/10/24 13:06:05 jmcneill Exp $

--- libao2/ao_sun.c.orig	2010-02-20 21:02:49.000000000 +0000
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
 
@@ -164,7 +168,7 @@ static int realtime_samplecounter_availa
 	goto error;
     }
 
-    if (ioctl(fd, AUDIO_GETINFO, &info)) {
+    if (ioctl(fd, AUDIO_GETBUFINFO, &info)) {
 	if ( mp_msg_test(MSGT_AO,MSGL_V) )
 	    perror("rtsc: GETINFO1");
 	goto error;
@@ -186,7 +190,7 @@ static int realtime_samplecounter_availa
 	if (usec_delay > 200000)
 	    break;
 
-	if (ioctl(fd, AUDIO_GETINFO, &info)) {
+	if (ioctl(fd, AUDIO_GETBUFINFO, &info)) {
 	    if ( mp_msg_test(MSGT_AO,MSGL_V) )
 		perror("rtsc: GETINFO2 failed");
 	    goto error;
@@ -650,7 +654,7 @@ static int get_space(void){
     }
 #endif
 
-    ioctl(audio_fd, AUDIO_GETINFO, &info);
+    ioctl(audio_fd, AUDIO_GETBUFINFO, &info);
 #if !defined (__OpenBSD__) && !defined(__NetBSD__)
     if (queued_bursts - info.play.eof > 2)
 	return 0;
@@ -684,7 +688,7 @@ static int play(void* data,int len,int f
 // return: delay in seconds between first and last sample in buffer
 static float get_delay(void){
     audio_info_t info;
-    ioctl(audio_fd, AUDIO_GETINFO, &info);
+    ioctl(audio_fd, AUDIO_GETBUFINFO, &info);
 #if defined (__OpenBSD__) || defined(__NetBSD__)
     return (float) info.play.seek/ (float)byte_per_sec ;
 #else
