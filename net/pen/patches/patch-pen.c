$NetBSD: patch-pen.c,v 1.1 2016/03/29 21:46:48 khorben Exp $

Fix build without support for SSLv2

--- pen.c.orig	2007-09-12 06:26:31.000000000 +0000
+++ pen.c
@@ -56,7 +56,9 @@
 #include <openssl/err.h>
 
 #define SRV_SSL_V23 0
-#define SRV_SSL_V2 1
+#ifndef OPENSSL_NO_SSL2
+# define SRV_SSL_V2 1
+#endif
 #define SRV_SSL_V3 2
 #define SRV_SSL_TLS1 3
 
@@ -327,9 +329,11 @@ static int ssl_init(void)
 	SSL_load_error_strings();
 	SSLeay_add_ssl_algorithms();
 	switch (ssl_protocol) {
+#ifndef OPENSSL_NO_SSL2
 	case SRV_SSL_V2:
 		ssl_context = SSL_CTX_new(SSLv2_method());
 		break;
+#endif
 	case SRV_SSL_V3:
 		ssl_context = SSL_CTX_new(SSLv3_method());
 		break;
@@ -2625,8 +2629,10 @@ static int options(int argc, char **argv
 		case 'L':
 			if (strcmp(optarg, "ssl23") == 0)
 				ssl_protocol = SRV_SSL_V23;
+#ifndef OPENSSL_NO_SSL2
 			else if (strcmp(optarg, "ssl2") == 0)
 				ssl_protocol = SRV_SSL_V2;
+#endif
 			else if (strcmp(optarg, "ssl3") == 0)
 				ssl_protocol = SRV_SSL_V3;
 			else if (strcmp(optarg, "tls1") == 0)
