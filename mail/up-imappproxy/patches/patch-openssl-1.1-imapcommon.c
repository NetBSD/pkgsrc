$NetBSD: patch-openssl-1.1-imapcommon.c,v 1.1 2020/04/17 11:28:02 tm Exp $

Fix compilation with OpenSSL 1.1

Richard Laager <rlaager@wiktel.com>
https://sourceforge.net/p/squirrelmail/mailman/message/35526927/

--- src/main.c.orig
+++ src/main.c
@@ -1582,9 +1582,9 @@
 	    verify_error = X509_V_ERR_CERT_CHAIN_TOO_LONG;
 	}
     }
-    switch (ctx->error) {
+    switch (err) {
     case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
-	X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert), buf, sizeof(buf));
+	X509_NAME_oneline(X509_get_issuer_name(err_cert), buf, sizeof(buf));
 	syslog(LOG_NOTICE, "issuer= %s", buf);
 	break;
     case X509_V_ERR_CERT_NOT_YET_VALID:
