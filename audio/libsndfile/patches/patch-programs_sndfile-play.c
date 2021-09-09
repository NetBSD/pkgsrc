$NetBSD: patch-programs_sndfile-play.c,v 1.3 2021/09/09 12:14:42 nia Exp $

Add support for NetBSD sun-like audio devices.
Do not change mixing parameters in the sun code.

--- programs/sndfile-play.c.orig	2020-10-04 10:00:49.000000000 +0000
+++ programs/sndfile-play.c
@@ -64,7 +64,7 @@
 #elif HAVE_SNDIO_H
 	#include <sndio.h>
 
-#elif (defined (sun) && defined (unix))
+#elif (defined (sun) && defined (unix)) || defined(__NetBSD__)
 	#include <fcntl.h>
 	#include <sys/ioctl.h>
 	#include <sys/audioio.h>
@@ -727,7 +727,7 @@ sndio_play (int argc, char *argv [])
 **	Solaris.
 */
 
-#if (defined (sun) && defined (unix)) /* ie Solaris */
+#if (defined (sun) && defined (unix)) || defined(__NetBSD__) /* ie Solaris */
 
 static void
 solaris_play (int argc, char *argv [])
@@ -764,8 +764,6 @@ solaris_play (int argc, char *argv [])
 		audio_info.play.channels = sfinfo.channels ;
 		audio_info.play.precision = 16 ;
 		audio_info.play.encoding = AUDIO_ENCODING_LINEAR ;
-		audio_info.play.gain = AUDIO_MAX_GAIN ;
-		audio_info.play.balance = AUDIO_MID_BALANCE ;
 
 		if ((error = ioctl (audio_fd, AUDIO_SETINFO, &audio_info)))
 		{	perror ("ioctl (AUDIO_SETINFO) failed") ;
@@ -845,7 +843,7 @@ main (int argc, char *argv [])
 	opensoundsys_play (argc, argv) ;
 #elif HAVE_SNDIO_H
 	sndio_play (argc, argv) ;
-#elif (defined (sun) && defined (unix))
+#elif (defined (sun) && defined (unix)) || defined(__NetBSD__)
 	solaris_play (argc, argv) ;
 #elif (OS_IS_WIN32 == 1)
 	win32_play (argc, argv) ;
