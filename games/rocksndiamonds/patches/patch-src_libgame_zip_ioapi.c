$NetBSD: patch-src_libgame_zip_ioapi.c,v 1.1 2026/01/26 16:25:31 adam Exp $

Fix build on NetBSD.

--- src/libgame/zip/ioapi.c.orig	2026-01-26 15:47:53.911344416 +0000
+++ src/libgame/zip/ioapi.c
@@ -16,7 +16,7 @@
 #include <stdlib.h>
 #include <string.h>
 
-#if defined unix || defined __APPLE__
+#if defined unix || defined __APPLE__ || defined __NetBSD__
 #include <sys/types.h>
 #include <unistd.h>
 #endif
