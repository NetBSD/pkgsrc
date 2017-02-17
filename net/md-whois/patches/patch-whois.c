$NetBSD: patch-whois.c,v 1.1 2017/02/17 17:10:37 joerg Exp $

--- whois.c.orig	2017-02-17 12:02:02.670565721 +0000
+++ whois.c
@@ -19,6 +19,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netdb.h>
