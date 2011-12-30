$NetBSD: patch-appl_telnet_libtelnet_encrypt.c,v 1.1 2011/12/30 18:59:06 tez Exp $

Fix for CVE-2011-4862 from FreeBSD

When an encryption key is supplied via the TELNET protocol, its length
is not validated before the key is copied into a fixed-size buffer.

--- appl/telnet/libtelnet/encrypt.c.orig	2011-12-30 11:55:11.373531000 -0600
+++ appl/telnet/libtelnet/encrypt.c	2011-12-30 11:56:35.109601000 -0600
@@ -736,6 +736,9 @@
     int dir = kp->dir;
     int ret = 0;
 
+    if (len > MAXKEYLEN)
+	len = MAXKEYLEN;
+
     if (!(ep = (*kp->getcrypt)(*kp->modep))) {
 	if (len == 0)
 	    return;
