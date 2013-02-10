$NetBSD: patch-playlist__file.c,v 1.2 2013/02/10 08:39:00 ryoon Exp $

--- playlist_file.c.orig	2012-08-16 06:44:35.000000000 +0000
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
@@ -412,9 +414,11 @@ static int plist_save_m3u (struct plist 
 		return 0;
 	}
 
+#ifndef __sun
 	/* Lock gets released by fclose(). */
 	if (flock (fileno (file), LOCK_EX) == -1)
 		logit ("Can't flock() the playlist file: %s", strerror (errno));
+#endif
 
 	if (fprintf (file, "#EXTM3U\r\n") < 0) {
 		error ("Error writing playlist: %s", strerror (errno));
