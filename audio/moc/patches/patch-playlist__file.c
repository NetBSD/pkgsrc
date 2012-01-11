$NetBSD: patch-playlist__file.c,v 1.1 2012/01/11 19:06:25 hans Exp $

--- playlist_file.c.orig	2007-07-30 16:58:46.000000000 +0200
+++ playlist_file.c	2011-12-30 17:36:48.654368031 +0100
@@ -91,8 +91,10 @@ static int plist_load_m3u (struct plist 
 		return 0;
 	}
 
+#ifndef __sun
 	if (flock(fileno(file), LOCK_SH) == -1)
 		logit ("Can't flock() the playlist file: %s", strerror(errno));
+#endif
 
 	while ((line = read_line(file))) {
 		if (!strncmp(line, "#EXTINF:", sizeof("#EXTINF:")-1)) {
@@ -190,9 +192,12 @@ static int plist_load_m3u (struct plist 
 		free (line);
 	}
 	
+#ifndef __sun
 	if (flock(fileno(file), LOCK_UN) == -1)
 		logit ("Can't flock() (unlock) the playlist file: %s",
 				strerror(errno));
+#endif
+
 	fclose (file);
 
 	return added;
@@ -432,8 +437,10 @@ static int plist_save_m3u (struct plist 
 		return 0;
 	}
 
+#ifndef __sun
 	if (flock(fileno(file), LOCK_EX) == -1)
 		logit ("Can't flock() the playlist file: %s", strerror(errno));
+#endif
 	
 	if (fprintf(file, "#EXTM3U\r\n") < 0) {
 		error ("Error writing playlist: %s", strerror(errno));
@@ -481,9 +488,12 @@ static int plist_save_m3u (struct plist 
 			}
 		}
 				
+#ifndef __sun
 	if (flock(fileno(file), LOCK_UN) == -1)
 		logit ("Can't flock() (unlock) the playlist file: %s",
 				strerror(errno));
+#endif
+
 	if (fclose(file)) {
 		error ("Error writing playlist: %s", strerror(errno));
 		return 0;
