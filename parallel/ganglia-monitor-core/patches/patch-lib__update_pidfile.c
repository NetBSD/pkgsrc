$NetBSD: patch-lib__update_pidfile.c,v 1.1 2016/02/16 12:48:18 fhajny Exp $

Portability.

--- lib/update_pidfile.c.orig	2015-07-01 19:49:35.000000000 +0000
+++ lib/update_pidfile.c
@@ -1,7 +1,7 @@
 /**
  * @file update_pidfile.c Functions for standalone daemons
  */
-#define _XOPEN_SOURCE 500 /* for getpgid */
+#define _XOPEN_SOURCE 700 /* for getpgid */
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdio.h>
