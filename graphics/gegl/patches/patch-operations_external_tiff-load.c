$NetBSD: patch-operations_external_tiff-load.c,v 1.2 2026/09/12 21:49:46 wiz Exp $

Fix SunOS flags.

--- operations/external/tiff-load.c.orig	2026-09-07 02:51:56.000000000 +0000
+++ operations/external/tiff-load.c
@@ -19,7 +19,9 @@
 #include "config.h"
 
 #ifdef HAVE_STRPTIME
+#  ifndef __sun
 #define _XOPEN_SOURCE
+#  endif
 #include <time.h>
 #endif
 
