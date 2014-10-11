$NetBSD: patch-src_pkg_crypto_x509_root__unix.go,v 1.1 2014/10/11 16:41:47 khorben Exp $

Also look for the right path for the SSL certificate repository on NetBSD.

--- src/pkg/crypto/x509/root_unix.go.orig	2014-10-08 19:16:18.000000000 +0000
+++ src/pkg/crypto/x509/root_unix.go
@@ -13,6 +13,7 @@ var certFiles = []string{
 	"/etc/ssl/certs/ca-certificates.crt",     // Debian/Ubuntu/Gentoo etc.
 	"/etc/pki/tls/certs/ca-bundle.crt",       // Fedora/RHEL
 	"/etc/ssl/ca-bundle.pem",                 // OpenSUSE
+	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
 	"/etc/ssl/cert.pem",                      // OpenBSD
 	"/usr/local/share/certs/ca-root-nss.crt", // FreeBSD/DragonFly
 }
