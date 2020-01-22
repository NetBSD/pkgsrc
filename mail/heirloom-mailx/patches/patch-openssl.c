$NetBSD: patch-openssl.c,v 1.2 2020/01/22 20:50:34 sevan Exp $

- remove SSL2 support since it is no longer supported by OpenSSL.
- fix build against modern OpenSSL
  from https://github.com/maximeh/buildroot/commit/9f145e4957fa562ed8df89527433fccd438b3502

--- openssl.c.orig	2011-04-26 21:23:22.000000000 +0000
+++ openssl.c
@@ -137,11 +137,13 @@ ssl_rand_init(void)
 
 	if ((cp = value("ssl-rand-egd")) != NULL) {
 		cp = expand(cp);
+#ifndef OPENSSL_NO_EGD
 		if (RAND_egd(cp) == -1) {
 			fprintf(stderr, catgets(catd, CATSET, 245,
 				"entropy daemon at \"%s\" not available\n"),
 					cp);
 		} else
+#endif
 			state = 1;
 	} else if ((cp = value("ssl-rand-file")) != NULL) {
 		cp = expand(cp);
@@ -216,12 +218,15 @@ ssl_select_method(const char *uhp)
 
 	cp = ssl_method_string(uhp);
 	if (cp != NULL) {
-		if (equal(cp, "ssl2"))
-			method = SSLv2_client_method();
-		else if (equal(cp, "ssl3"))
+		#ifndef OPENSSL_NO_SSL3
+		if (equal(cp, "ssl3"))
 			method = SSLv3_client_method();
 		else if (equal(cp, "tls1"))
 			method = TLSv1_client_method();
+		#else
+		if (equal(cp, "tls1"))
+			method = TLSv1_client_method();
+		#endif
 		else {
 			fprintf(stderr, catgets(catd, CATSET, 244,
 					"Invalid SSL method \"%s\"\n"), cp);
