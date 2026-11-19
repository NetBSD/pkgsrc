$NetBSD: patch-doc_examples_tlsproxy_tlsproxy.c,v 1.4 2026/11/19 03:22:19 wiz Exp $

Portability fix: %m is not available outside of syslog()
https://gitlab.com/gnutls/gnutls/-/work_items/2028

--- doc/examples/tlsproxy/tlsproxy.c.orig	2026-11-18 16:39:19.000000000 +0000
+++ doc/examples/tlsproxy/tlsproxy.c
@@ -102,7 +102,8 @@ static int bindtoaddress(char *addrport)
 	}
 
 	if (!rp) {
-		fprintf(stderr, "Error binding to %s:%s: %m\n", addr, port);
+		fprintf(stderr, "Error binding to %s:%s: %s\n", addr, port,
+			strerror(errno));	
 		freeaddrinfo(result);
 		return -1;
 	}
@@ -160,7 +161,8 @@ static int connecttoaddress(char *addrport)
 	}
 
 	if (!rp) {
-		fprintf(stderr, "Error connecting to %s:%s: %m\n", addr, port);
+		fprintf(stderr, "Error connecting to %s:%s: %s\n", addr, port,
+			strerror(errno));
 		freeaddrinfo(result);
 		return -1;
 	}
