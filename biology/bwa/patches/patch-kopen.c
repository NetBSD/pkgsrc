$NetBSD: patch-kopen.c,v 1.3 2017/12/27 23:44:01 he Exp $

Add includes for getting timevals and select prototype into scope.

--- kopen.c.orig	2017-10-23 17:10:17.000000000 +0000
+++ kopen.c
@@ -12,6 +12,8 @@
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <sys/socket.h>
+#include <sys/time.h>
+#include <sys/select.h>
 #endif
 
 #ifdef USE_MALLOC_WRAPPERS
