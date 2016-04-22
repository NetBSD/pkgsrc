$NetBSD: patch-plugins_mmexternal_mmexternal.c,v 1.4 2016/04/22 16:52:14 jperkin Exp $

Fix build on BSD.
--- plugins/mmexternal/mmexternal.c.orig	2016-03-02 11:12:44.000000000 +0000
+++ plugins/mmexternal/mmexternal.c
@@ -31,7 +31,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFlyBSD__) || defined(__APPLE__)
 #include <sys/wait.h>
 #else
 #include <wait.h>
