$NetBSD: patch-src_drivers_netbsd.c,v 1.1 2011/04/05 05:22:52 rxg Exp $

--- src/drivers/netbsd.c.orig	2010-01-09 22:34:20.000000000 +0000
+++ src/drivers/netbsd.c
@@ -174,7 +174,7 @@ static void bufdump(struct xmp_context *
 	while (i) {
 		if ((j = write(audio_fd, b, i)) > 0) {
 			i -= j;
-			(char *)b += j;
+			b = (char *)b + j;
 		} else
 			break;
 	}
