$NetBSD: patch-openssl.c,v 1.1 2014/12/28 14:16:14 bsiegert Exp $

Imported Debian package fixes:
- remove SSL2 support since it is no longer supported by OpenSSL.

--- openssl.c.orig	2011-04-26 21:23:22.000000000 +0000
+++ openssl.c
@@ -216,9 +216,7 @@ ssl_select_method(const char *uhp)
 
 	cp = ssl_method_string(uhp);
 	if (cp != NULL) {
-		if (equal(cp, "ssl2"))
-			method = SSLv2_client_method();
-		else if (equal(cp, "ssl3"))
+		if (equal(cp, "ssl3"))
 			method = SSLv3_client_method();
 		else if (equal(cp, "tls1"))
 			method = TLSv1_client_method();
