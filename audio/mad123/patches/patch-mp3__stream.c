$NetBSD: patch-mp3__stream.c,v 1.1 2012/02/15 22:09:31 hans Exp $

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
