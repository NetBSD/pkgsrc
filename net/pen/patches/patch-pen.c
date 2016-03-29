$NetBSD: patch-pen.c,v 1.2 2016/03/29 22:01:13 joerg Exp $

--- pen.c.orig	2016-03-28 18:32:43.989295691 +0000
+++ pen.c
@@ -56,7 +56,6 @@
 #include <openssl/err.h>
 
 #define SRV_SSL_V23 0
-#define SRV_SSL_V2 1
 #define SRV_SSL_V3 2
 #define SRV_SSL_TLS1 3
 
@@ -327,9 +326,6 @@ static int ssl_init(void)
 	SSL_load_error_strings();
 	SSLeay_add_ssl_algorithms();
 	switch (ssl_protocol) {
-	case SRV_SSL_V2:
-		ssl_context = SSL_CTX_new(SSLv2_method());
-		break;
 	case SRV_SSL_V3:
 		ssl_context = SSL_CTX_new(SSLv3_method());
 		break;
@@ -346,6 +342,7 @@ static int ssl_init(void)
 		error("SSL: Error allocating context: %s",
 			ERR_error_string(err, NULL));
 	}
+	SSL_CTX_set_options(ssl_context, SSL_OP_NO_SSLv2);
 	if (ssl_compat) {
 		SSL_CTX_set_options(ssl_context, SSL_OP_ALL);
 	}
@@ -2625,8 +2622,6 @@ static int options(int argc, char **argv
 		case 'L':
 			if (strcmp(optarg, "ssl23") == 0)
 				ssl_protocol = SRV_SSL_V23;
-			else if (strcmp(optarg, "ssl2") == 0)
-				ssl_protocol = SRV_SSL_V2;
 			else if (strcmp(optarg, "ssl3") == 0)
 				ssl_protocol = SRV_SSL_V3;
 			else if (strcmp(optarg, "tls1") == 0)
