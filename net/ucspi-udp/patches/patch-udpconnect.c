$NetBSD: patch-udpconnect.c,v 1.1 2021/11/15 10:08:17 schmonz Exp $

Provide definition of struct timeval.

--- udpconnect.c.orig	2016-03-29 19:44:38.000000000 +0000
+++ udpconnect.c
@@ -1,3 +1,4 @@
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/param.h>
 #include <netdb.h>
