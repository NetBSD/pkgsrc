$NetBSD: patch-src_crypto_x509_root__bsd.go,v 1.1 2020/08/21 19:50:22 bsiegert Exp $

--- src/crypto/x509/root_bsd.go.orig	2017-07-24 19:38:15.000000000 +0000
+++ src/crypto/x509/root_bsd.go
@@ -12,4 +12,5 @@ var certFiles = []string{
 	"/etc/ssl/cert.pem",                      // OpenBSD
 	"/usr/local/share/certs/ca-root-nss.crt", // DragonFly
 	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
+	"/etc/ssl/certs/ca-certificates.crt",     // NetBSD
 }
