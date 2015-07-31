$NetBSD: patch-src_crypto_x509_root__unix.go,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Also look for the right path for the SSL certificate repository on NetBSD.
https://github.com/golang/go/issues/9285

--- src/crypto/x509/root_unix.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/crypto/x509/root_unix.go
@@ -13,6 +13,7 @@ var certFiles = []string{
 	"/etc/ssl/certs/ca-certificates.crt",     // Debian/Ubuntu/Gentoo etc.
 	"/etc/pki/tls/certs/ca-bundle.crt",       // Fedora/RHEL
 	"/etc/ssl/ca-bundle.pem",                 // OpenSUSE
+	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
 	"/etc/ssl/cert.pem",                      // OpenBSD
 	"/usr/local/share/certs/ca-root-nss.crt", // FreeBSD/DragonFly
 	"/etc/pki/tls/cacert.pem",                // OpenELEC
