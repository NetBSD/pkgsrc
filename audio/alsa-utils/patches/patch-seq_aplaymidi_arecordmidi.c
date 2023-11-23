$NetBSD: patch-seq_aplaymidi_arecordmidi.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- seq/aplaymidi/arecordmidi.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ seq/aplaymidi/arecordmidi.c
@@ -719,7 +719,7 @@ static void version(void)
 	fputs("arecordmidi version " SND_UTIL_VERSION_STR "\n", stderr);
 }
 
-static void sighandler(int)
+static void sighandler(int sig ATTRIBUTE_UNUSED)
 {
 	stop = 1;
 }
