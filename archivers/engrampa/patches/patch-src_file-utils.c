$NetBSD: patch-src_file-utils.c,v 1.1 2026/01/16 22:35:49 wiz Exp $

Add missing header for strcasecmp().

--- src/file-utils.c.orig	2026-01-16 22:34:55.564344005 +0000
+++ src/file-utils.c
@@ -27,6 +27,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <ctype.h>
 #include <time.h>
 #include <unistd.h>
