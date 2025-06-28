$NetBSD: patch-src_histedit.c,v 1.1 2025/06/28 02:40:08 schmonz Exp $

Avoid "'optreset' undeclared" on Illumos.

--- src/histedit.c.orig	2025-06-28 02:26:40.738340552 +0000
+++ src/histedit.c
@@ -217,6 +217,8 @@ histcmd(int argc, char **argv)
 
 #ifdef __GLIBC__
 	optind = 0;
+#elif defined(__sun)
+	optind = 1;
 #else
 	optreset = 1; optind = 1; /* initialize getopt */
 #endif
