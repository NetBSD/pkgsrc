$NetBSD: patch-pfbtops_pfbtops.c,v 1.1 2026/03/22 10:34:03 nia Exp $

Fix implicit function declarations.

--- pfbtops/pfbtops.c.orig	2026-03-22 10:14:42.187136892 +0000
+++ pfbtops/pfbtops.c
@@ -1,6 +1,8 @@
 /* This translates ps fonts in .pfb format to ASCII ps files. */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
 
 /* Binary bytes per output line. */
 #define BYTES_PER_LINE (64/2)
