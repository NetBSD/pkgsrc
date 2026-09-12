$NetBSD: patch-operations_external_png-load.c,v 1.2 2026/09/12 21:49:46 wiz Exp $

Fix SunOS flags.

--- operations/external/png-load.c.orig	2026-09-07 02:51:56.000000000 +0000
+++ operations/external/png-load.c
@@ -25,7 +25,9 @@
 #endif
 
 #ifdef HAVE_STRPTIME
+#  ifndef __sun
 #define _XOPEN_SOURCE
+#  endif
 #include <time.h>
 #endif
 
