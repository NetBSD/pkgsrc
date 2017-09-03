$NetBSD: patch-src_crypto_x509_root__bsd.go,v 1.2 2017/09/03 07:12:07 bsiegert Exp $

--- src/crypto/x509/root_bsd.go.orig	2017-07-24 19:38:15.000000000 +0000
+++ src/crypto/x509/root_bsd.go
@@ -12,4 +12,5 @@ var certFiles = []string{
 	"/etc/ssl/cert.pem",                      // OpenBSD
 	"/usr/local/share/certs/ca-root-nss.crt", // DragonFly
 	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
+	"/etc/ssl/certs/ca-certificates.crt",     // NetBSD
 }
