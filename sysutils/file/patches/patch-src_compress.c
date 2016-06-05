$NetBSD: patch-src_compress.c,v 1.2 2016/06/05 13:57:37 mef Exp $
sig_t is not defined by default on SunOS

--- src/compress.c.orig	2016-04-20 09:00:26.000000000 +0900
+++ src/compress.c	2016-06-05 22:54:06.000000000 +0900
@@ -67,6 +67,10 @@ typedef void (*sig_t)(int);
 #include <zlib.h>
 #define ZLIBSUPPORT
 #endif
+/* sig_t is not defined by default on SunOS */
+#ifdef __sun
+typedef void (*sig_t)(int);
+#endif
 #ifdef DEBUG
 int tty = -1;
 #define DPRINTF(...)	do { \
