$NetBSD: patch-lpass.c,v 1.1 2025/09/08 08:09:18 vins Exp $

libgen.h is also needed on SunOS for basename().

--- lpass.c.orig	2025-09-08 08:01:58.935555860 +0000
+++ lpass.c
@@ -46,7 +46,7 @@
 #include <getopt.h>
 #include <unistd.h>
 
-#if (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if (defined(__APPLE__) && defined(__MACH__)) || defined (__sun) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <libgen.h>
 #endif
 
