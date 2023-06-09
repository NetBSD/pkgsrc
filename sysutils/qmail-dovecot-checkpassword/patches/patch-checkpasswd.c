$NetBSD: patch-checkpasswd.c,v 1.1 2023/06/09 19:38:24 schmonz Exp $

Find Dovecot socket in VARBASE.

--- checkpasswd.c.orig	2014-11-25 13:40:32.000000000 +0000
+++ checkpasswd.c
@@ -12,7 +12,7 @@
 #include "base64.h"
 
 #define BUFSIZE 513
-#define AUTHSOCKET "/var/run/dovecot/auth-client"
+#define AUTHSOCKET "@VARBASE@/run/dovecot/auth-client"
 
 int connect_sock(struct sockaddr_un *sock_addr)
 {
