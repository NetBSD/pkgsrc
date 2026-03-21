$NetBSD: patch-src_stats-sol.c,v 1.1 2026/03/21 10:38:34 nia Exp $

Fix implicit function declarations.

--- src/stats-sol.c.orig	2026-03-21 10:18:21.173346657 +0000
+++ src/stats-sol.c
@@ -11,9 +11,11 @@
 
 /* System includes */
 #include <stdio.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <utmpx.h>
 #include <fcntl.h>
+#include <unistd.h>
 #include <strings.h>
 #include <sys/stat.h>
 #include <sys/types.h>
