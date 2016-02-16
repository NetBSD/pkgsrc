$NetBSD: patch-playlist__file.c,v 1.2 2016/02/16 08:46:01 leot Exp $

--- playlist_file.c.orig	2014-08-30 02:31:51.000000000 +0000
+++ playlist_file.c
@@ -90,9 +90,11 @@ static int plist_load_m3u (struct plist 
 		return 0;
 	}
 
+#ifndef __sun
 	/* Lock gets released by fclose(). */
 	if (flock (fileno (file), LOCK_SH) == -1)
 		logit ("Can't flock() the playlist file: %s", strerror (errno));
+#endif
 
 	while ((line = read_line (file))) {
 		if (!strncmp (line, "#EXTINF:", sizeof("#EXTINF:") - 1)) {
@@ -411,9 +413,11 @@ static int plist_save_m3u (struct plist 
 		return 0;
 	}
 
+#ifndef __sun
 	/* Lock gets released by fclose(). */
 	if (flock (fileno (file), LOCK_EX) == -1)
 		logit ("Can't flock() the playlist file: %s", strerror (errno));
+#endif
 
 	if (fprintf (file, "#EXTM3U\r\n") < 0) {
 		error ("Error writing playlist: %s", strerror (errno));
