$NetBSD: patch-loudmouth_lm-sock.c,v 1.1 2014/05/19 09:34:34 jperkin Exp $

Darwin does not have TCP_KEEPIDLE.

--- loudmouth/lm-sock.c.orig	2008-10-29 13:45:10.000000000 +0000
+++ loudmouth/lm-sock.c
@@ -325,10 +325,12 @@ _lm_sock_set_keepalive (LmSocketT sock, 
 		return FALSE;
 	}
 
+#ifndef __APPLE__
 	opt = delay;
 	if (setsockopt (sock, IPPROTO_TCP, TCP_KEEPIDLE, &opt, sizeof (opt)) < 0) {
 		return FALSE;
 	}
+#endif
 
 	opt = delay; 
 	if (setsockopt (sock, IPPROTO_TCP, TCP_KEEPINTVL, &opt, sizeof (opt)) < 0) {
