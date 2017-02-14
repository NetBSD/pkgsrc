$NetBSD: patch-kopen.c,v 1.1 2017/02/14 21:34:34 joerg Exp $

--- kopen.c.orig	2017-02-09 15:42:47.246248867 +0000
+++ kopen.c
@@ -8,6 +8,7 @@
 #include <signal.h>
 #include <sys/wait.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #ifndef _WIN32
 #include <netdb.h>
 #include <arpa/inet.h>
