$NetBSD: patch-src_crypto_x509_root__bsd.go,v 1.1 2021/08/22 13:10:18 bsiegert Exp $

--- src/crypto/x509/root_bsd.go.orig	2020-12-17 16:09:06.000000000 +0000
+++ src/crypto/x509/root_bsd.go
@@ -12,6 +12,7 @@ var certFiles = []string{
 	"/etc/ssl/cert.pem",                      // OpenBSD
 	"/usr/local/share/certs/ca-root-nss.crt", // DragonFly
 	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
+	"/etc/ssl/certs/ca-certificates.crt",     // NetBSD
 }
 
 // Possible directories with certificate files; stop after successfully
