$NetBSD: patch-src_drivers_netbsd.c,v 1.4 2019/11/21 23:59:06 nia Exp $

--- src/sound_netbsd.c.orig	2016-07-16 11:29:44.213738881 +0000
+++ src/sound_netbsd.c
@@ -36,7 +36,7 @@ static int init(struct options *options)
 	chkparm1("buffer", bsize = strtoul(token, NULL, 0));
 	parm_end();
 
-	if ((audio_fd = open("/dev/sound", O_WRONLY)) == -1)
+	if ((audio_fd = open("/dev/audio", O_WRONLY)) == -1)
 		return -1;
 
 	/* try to open audioctldevice */
@@ -101,7 +101,7 @@ static void play(void *b, int i)
 	while (i) {
 		if ((j = write(audio_fd, b, i)) > 0) {
 			i -= j;
-			(char *)b += j;
+			b = (char *)b + j;
 		} else
 			break;
 	}
