$NetBSD: patch-ee.c,v 1.1 2022/12/06 11:38:00 vins Exp $

Portability fix for POSIX <signal.h>

--- ee.c.orig	2010-06-04 01:56:36.000000000 +0000
+++ ee.c
@@ -111,6 +111,10 @@ nl_catd catalog;
 #define SIGCHLD SIGCLD
 #endif
 
+#ifndef	SIGUNUSED
+#define SIGUNUSED SIGSYS
+#endif
+
 #define TAB 9
 #define max(a, b)	(a > b ? a : b)
 #define min(a, b)	(a < b ? a : b)
