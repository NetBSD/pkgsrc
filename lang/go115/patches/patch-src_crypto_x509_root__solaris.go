$NetBSD: patch-src_crypto_x509_root__solaris.go,v 1.1 2021/03/30 14:53:35 jperkin Exp $

Use pkgsrc certificates by default.

--- src/crypto/x509/root_solaris.go.orig	2021-01-19 20:01:09.000000000 +0000
+++ src/crypto/x509/root_solaris.go
@@ -6,6 +6,7 @@ package x509
 
 // Possible certificate files; stop after finding one.
 var certFiles = []string{
+	"@PKG_SYSCONFDIR@/openssl/certs/ca-certificates.crt",
 	"/etc/certs/ca-certificates.crt",     // Solaris 11.2+
 	"/etc/ssl/certs/ca-certificates.crt", // Joyent SmartOS
 	"/etc/ssl/cacert.pem",                // OmniOS
