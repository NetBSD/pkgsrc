$NetBSD: patch-mp3__stream.c,v 1.2 2025/06/05 10:46:26 martin Exp $

fix build on Solaris derivates
fix build with newer curl versions

--- mp3_stream.c.orig	2004-10-21 11:11:42.000000000 +0200
+++ mp3_stream.c	2012-01-11 19:53:46.065401047 +0100
@@ -41,6 +41,11 @@
 #endif /* NOTAGLIB */
 #include <unistd.h>	/* Move *after* curl.h, 'cos it's braindamaged */
 
+#ifdef __sun
+#define madvise posix_madvise
+#define MAP_FILE 0
+#endif
+
 #include "mp3_stream.h"
 
 static void	*mps_file_open(const char *, int);
@@ -645,9 +645,9 @@ mps_url_spawn_reader(const char *path, i
 	curl_easy_setopt(ch, CURLOPT_WRITEFUNCTION, mps_url_writer);
 	curl_easy_setopt(ch, CURLOPT_FILE, fp);
 	curl_easy_setopt(ch, CURLOPT_URL, path);
-	curl_easy_setopt(ch, CURLOPT_NOPROGRESS, 1);
-	curl_easy_setopt(ch, CURLOPT_FAILONERROR, 1);
-	curl_easy_setopt(ch, CURLOPT_FOLLOWLOCATION, 1);
+	curl_easy_setopt(ch, CURLOPT_NOPROGRESS, 1L);
+	curl_easy_setopt(ch, CURLOPT_FAILONERROR, 1L);
+	curl_easy_setopt(ch, CURLOPT_FOLLOWLOCATION, 1L);
 
 	curl_easy_perform(ch);
 	exit(1);

