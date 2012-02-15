$NetBSD: patch-src_wildmidi.c,v 1.2 2012/02/15 22:05:24 hans Exp $

On NetBSD, FNONBLOCK is only defined for the kernel.
Define MAP_FILE if necessary.
Fix device name in printf.

--- src/wildmidi.c.orig	2010-07-30 00:33:46.000000000 +0000
+++ src/wildmidi.c
@@ -63,7 +63,15 @@
 #include "wildmidi_lib.h"
 
 #ifndef FNONBLOCK
+#ifdef _FNONBLOCK
 #define FNONBLOCK _FNONBLOCK
+#else
+#define FNONBLOCK O_NONBLOCK
+#endif
+#endif
+
+#ifndef MAP_FILE
+#define MAP_FILE 0
 #endif
 
 
@@ -573,11 +581,11 @@ open_oss_output( void ) {
 	}
 
 	if ((audio_fd = open(pcmname, omode)) < 0) {
-		printf("ERROR: Unable to open /dev/dsp (%s)\r\n",strerror(errno));
+		printf("ERROR: Unable to open %s (%s)\r\n",pcmname, strerror(errno));
 		return -1;
 	}
 	if (ioctl (audio_fd, SNDCTL_DSP_RESET, 0) < 0) {
-		printf("ERROR: Unable to reset /dev/dsp\r\n");
+		printf("ERROR: Unable to reset %s\r\n, pcmname");
 		shutdown_output();
 		return -1;
 	}
