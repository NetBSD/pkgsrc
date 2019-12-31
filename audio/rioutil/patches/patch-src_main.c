$NetBSD: patch-src_main.c,v 1.1 2019/12/31 12:10:20 schmonz Exp $

Support DragonFly.

--- src/main.c.orig	2019-05-14 19:24:11.000000000 +0000
+++ src/main.c
@@ -942,7 +942,7 @@ static void usage (void) {
   printf("  -d, --delete=<int>     delete a track(s)\n\n");
 
   printf(" general options:\n");
-#if !defined(__FreeBSD__) || !defined(__NetBSD__)
+#if !defined(__FreeBSD__) || !defined(__NetBSD__) || !defined(__DragonFly__)
   printf("  -o, --device=<int>     minor number of rio (assigned by driver), /dev/usb/rio?\n");
 #else
   printf("  -o, --device=<int>     minor number of rio (assigned by driver), /dev/urio?\n");
