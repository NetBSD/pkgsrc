$NetBSD: patch-ssl__proxy.c,v 1.1 2026/06/20 09:53:16 nia Exp $

Need to include <strings.h> for bcopy(3), bzero(3).

--- ssl_proxy.c.orig	2026-06-20 09:51:07.617451911 +0000
+++ ssl_proxy.c
@@ -39,6 +39,7 @@
 #include <netdb.h>
 #include <fcntl.h>
 #include <string.h>
+#include <strings.h>
 #include <pwd.h>
 #include <arpa/inet.h>
 
