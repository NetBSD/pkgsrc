$NetBSD: patch-telnet_libtelnet_encrypt.c,v 1.1 2011/12/23 16:44:24 tez Exp $

Fix for CVE-2011-4862 from FreeBSD

When an encryption key is supplied via the TELNET protocol, its length
is not validated before the key is copied into a fixed-size buffer.

--- telnet/libtelnet/encrypt.c.orig	2011-12-23 10:14:18.191614600 -0600
+++ telnet/libtelnet/encrypt.c	2011-12-23 10:15:26.640275300 -0600
@@ -757,6 +757,9 @@
 	int dir = kp->dir;
 	register int ret = 0;
 
+	if (len > MAXKEYLEN)
+		len = MAXKEYLEN;
+
 	if (!(ep = (*kp->getcrypt)(*kp->modep))) {
 		if (len == 0)
 			return;
