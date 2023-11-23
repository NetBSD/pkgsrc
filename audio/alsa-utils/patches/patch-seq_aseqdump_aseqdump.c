$NetBSD: patch-seq_aseqdump_aseqdump.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- seq/aseqdump/aseqdump.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ seq/aseqdump/aseqdump.c
@@ -676,7 +676,7 @@ static void version(void)
 	puts("aseqdump version " SND_UTIL_VERSION_STR);
 }
 
-static void sighandler(int)
+static void sighandler(int sig ATTRIBUTE_UNUSED)
 {
 	stop = 1;
 }
