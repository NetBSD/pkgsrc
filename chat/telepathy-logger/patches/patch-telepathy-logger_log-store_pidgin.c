$NetBSD: patch-telepathy-logger_log-store_pidgin.c,v 1.2 2012/03/10 08:38:34 obache Exp $

--- telepathy-logger/log-store-pidgin.c.orig	2011-03-25 00:13:54.000000000 +0100
+++ telepathy-logger/log-store-pidgin.c	2012-01-22 14:26:33.292976356 +0100
@@ -21,7 +21,9 @@
 
 #include <config.h>
 
+#ifndef _XOPEN_SOURCE
 #define _XOPEN_SOURCE
+#endif
 #include <time.h>
 #include <string.h>
 #include <stdio.h>
