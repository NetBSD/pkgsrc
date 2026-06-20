$NetBSD: patch-src_dictionary.c,v 1.1 2026/06/20 00:52:49 nia Exp $

Define the correct standard version for ftello(3).

--- src/dictionary.c.orig	2026-06-20 00:44:31.904787286 +0000
+++ src/dictionary.c
@@ -30,7 +30,7 @@
  *
  */
 
-#define _POSIX_C_SOURCE 200808
+#define _POSIX_C_SOURCE 200809L
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
