$NetBSD: patch-src_crypto_x509_root__bsd.go,v 1.1 2016/01/31 10:17:27 bsiegert Exp $

--- src/crypto/x509/root_bsd.go.orig	2016-01-13 19:47:00.000000000 +0000
+++ src/crypto/x509/root_bsd.go
@@ -11,4 +11,5 @@ var certFiles = []string{
 	"/usr/local/share/certs/ca-root-nss.crt", // FreeBSD/DragonFly
 	"/etc/ssl/cert.pem",                      // OpenBSD
 	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
+	"/etc/ssl/certs/ca-certificates.crt",     // NetBSD
 }
