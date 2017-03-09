$NetBSD: patch-check__dotpid.c,v 1.1 2017/03/09 18:39:15 maya Exp $

Missing header on FreeBSD. PR pkg/52055

--- check_dotpid.c.orig	2015-08-16 03:22:35.000000000 +0000
+++ check_dotpid.c
@@ -40,6 +40,7 @@
 #include <time.h>
 #include <paths.h>
 #include <sys/param.h>
+#include <unistd.h>
 
 #ifndef STATE_OK
 #define STATE_OK        0
