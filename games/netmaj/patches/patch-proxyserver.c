$NetBSD: patch-proxyserver.c,v 1.1 2013/02/26 10:29:34 joerg Exp $

--- proxyserver.c.orig	2013-02-25 20:54:05.000000000 +0000
+++ proxyserver.c
@@ -61,6 +61,8 @@ int debug=0;
 
 char *cmd = "/bin/sh";
 
+static void proxy_start(void);
+
 void term() {
 	proxy_term();
 	exit(1);
@@ -224,7 +226,7 @@ if (debug) printf("sute %s\n",buf);
 	}
 }
 
-proxy_start() {
+static void proxy_start(void) {
 	char buf[256];
 	fd_set fds;
 	int maxfd;
