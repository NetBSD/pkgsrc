$NetBSD: patch-src_drivers_netbsd.c,v 1.3 2014/02/27 03:40:10 rxg Exp $

--- src/sound_netbsd.c.orig	2013-04-06 13:38:02.000000000 +0000
+++ src/sound_netbsd.c
@@ -99,7 +101,7 @@ static void play(void *b, int i)
 	while (i) {
 		if ((j = write(audio_fd, b, i)) > 0) {
 			i -= j;
-			(char *)b += j;
+			b = (char *)b + j;
 		} else
 			break;
 	}
