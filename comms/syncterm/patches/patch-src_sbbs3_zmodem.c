$NetBSD: patch-src_sbbs3_zmodem.c,v 1.1 2025/03/06 04:33:36 vins Exp $

Include <limits.h> for UINT_MAX

--- src/sbbs3/zmodem.c.orig	2025-02-11 18:23:24.000000000 +0000
+++ src/sbbs3/zmodem.c
@@ -35,6 +35,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdarg.h> /* va_list */
+#include <limits.h> /* UINT_MAX */
 #include <sys/stat.h>   /* struct stat */
 
 #include "genwrap.h"
