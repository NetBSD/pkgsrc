$NetBSD: patch-plugins_mmexternal_mmexternal.c,v 1.3 2015/08/26 00:55:33 fhajny Exp $

Fix build on BSD.
--- plugins/mmexternal/mmexternal.c.orig	2015-08-10 10:24:49.000000000 +0000
+++ plugins/mmexternal/mmexternal.c
@@ -31,7 +31,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFlyBSD__)
 #include <sys/wait.h>
 #else
 #include <wait.h>
