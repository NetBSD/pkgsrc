$NetBSD: patch-contrib_libexec_mail.local_mail.local.c,v 1.1 2023/08/24 15:26:40 vins Exp $

Initialize variable to silence warning.

--- contrib/libexec/mail.local/mail.local.c.orig	2020-05-21 19:06:04.000000000 +0000
+++ contrib/libexec/mail.local/mail.local.c
@@ -288,7 +288,7 @@ void
 notifybiff(char *msg)
 {
 	static struct addrinfo *res0;
-	struct addrinfo hints, *res;
+	struct addrinfo hints, *res = NULL;
 	static int f = -1;
 	size_t len;
 	int error;
