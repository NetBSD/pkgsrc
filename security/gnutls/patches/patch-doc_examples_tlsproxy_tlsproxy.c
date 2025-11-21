$NetBSD: patch-doc_examples_tlsproxy_tlsproxy.c,v 1.3 2025/11/21 16:44:56 manu Exp $

Portability fix: %m is not available outside of syslog()

--- ./doc/examples/tlsproxy/tlsproxy.c.orig	2025-11-21 10:22:50.551213704 +0100
+++ ./doc/examples/tlsproxy/tlsproxy.c	2025-11-21 10:24:24.693866421 +0100
@@ -101,9 +101,10 @@
 		}
 	}
 
 	if (!rp) {
-		fprintf(stderr, "Error binding to %s:%s: %m\n", addr, port);
+		fprintf(stderr, "Error binding to %s:%s: %s\n", addr, port,
+			strerror(errno));	
 		freeaddrinfo(result);
 		return -1;
 	}
 
@@ -159,9 +160,10 @@
 		}
 	}
 
 	if (!rp) {
-		fprintf(stderr, "Error connecting to %s:%s: %m\n", addr, port);
+		fprintf(stderr, "Error connecting to %s:%s: %s\n", addr, port,
+			strerror(errno));
 		freeaddrinfo(result);
 		return -1;
 	}
 
