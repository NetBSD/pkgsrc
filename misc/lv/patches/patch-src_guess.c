$NetBSD: patch-src_guess.c,v 1.1 2024/08/09 03:34:13 ryoon Exp $

For strncmp().

--- src/guess.c.orig	2024-08-08 02:03:51.242003993 +0000
+++ src/guess.c
@@ -36,6 +36,7 @@
 #endif
 #include <begin.h>
 #include <guess.h>
+#include <string.h>
 
 #ifndef MSDOS
 static int isUTF8( byte *str, int length )
