$NetBSD: patch-src_libtracker-extract_tracker-utils.c,v 1.1 2025/11/04 14:39:49 wiz Exp $

Restrict namespace games to Linux; this hides getline() on NetBSD.

--- src/libtracker-extract/tracker-utils.c.orig	2025-11-04 14:38:20.672097206 +0000
+++ src/libtracker-extract/tracker-utils.c
@@ -19,8 +19,10 @@
 
 #include "config-miners.h"
 
+#ifdef __linux__
 #define _XOPEN_SOURCE
 #define _XOPEN_SOURCE_EXTENDED 1	/* strptime is XPG4v2 */
+#endif
 
 #include <time.h>
 #include <string.h>
