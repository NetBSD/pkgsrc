$NetBSD: patch-extern.h,v 1.4 2026/08/31 14:02:05 vins Exp $

Add missing header for uint*_t types.

--- extern.h.orig	2026-08-31 04:45:33.623155744 +0000
+++ extern.h
@@ -21,6 +21,7 @@
 #include <fts.h> /* FTSENT */
 #include <stdbool.h>
 #include <stdio.h> /* FILE */
+#include <stdint.h> /* uint8_t */
 #include <time.h> /* struct timespec, gettimeofday(), etc. */
 
 #if !HAVE_PLEDGE
