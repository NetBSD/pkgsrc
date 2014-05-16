$NetBSD: patch-lib_ipc_server.c,v 1.1 2014/05/16 12:49:42 ryoon Exp $

* OpenBSD should use its own conditional.

--- lib/ipc/server.c.orig	2012-12-09 22:06:44.000000000 +0000
+++ lib/ipc/server.c
@@ -525,7 +525,7 @@ update_client_creds(struct client *c)
 	}
     }
 #endif
-#ifdef SO_PEERCRED
+#if defined(SO_PEERCRED) && !defined(__OpenBSD__)
     /* Linux */
     {
 	struct ucred pc;
