$NetBSD: patch-https.c,v 1.1 2021/07/12 21:32:49 schmonz Exp $

Provide a fallback definition on at least macOS Big Sur.

--- https.c.orig	2021-07-03 15:04:54.000000000 +0000
+++ https.c
@@ -32,6 +32,10 @@
 	exit(EXIT_SUCCESS);				\
 } while (0)
 
+#if !defined(HOST_NAME_MAX)
+#define HOST_NAME_MAX sysconf(_SC_HOST_NAME_MAX)
+#endif
+
 int
 main(void)
 {
