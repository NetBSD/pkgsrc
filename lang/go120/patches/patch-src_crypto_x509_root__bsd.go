$NetBSD: patch-src_crypto_x509_root__bsd.go,v 1.1 2023/02/05 13:25:26 bsiegert Exp $

--- src/crypto/x509/root_bsd.go.orig	2021-12-14 18:01:46.000000000 +0000
+++ src/crypto/x509/root_bsd.go
@@ -12,6 +12,7 @@ var certFiles = []string{
 	"/etc/ssl/cert.pem",                      // OpenBSD
 	"/usr/local/share/certs/ca-root-nss.crt", // DragonFly
 	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
+	"/etc/ssl/certs/ca-certificates.crt",     // NetBSD
 }
 
 // Possible directories with certificate files; all will be read.
@@ -19,4 +20,5 @@ var certDirectories = []string{
 	"/etc/ssl/certs",         // FreeBSD 12.2+
 	"/usr/local/share/certs", // FreeBSD
 	"/etc/openssl/certs",     // NetBSD
+	"/etc/ssl/certs",         // NetBSD
 }
