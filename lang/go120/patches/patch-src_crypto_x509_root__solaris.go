$NetBSD: patch-src_crypto_x509_root__solaris.go,v 1.1 2023/02/05 13:25:26 bsiegert Exp $

Use pkgsrc certificates by default.

--- src/crypto/x509/root_solaris.go.orig	2021-12-14 18:01:46.000000000 +0000
+++ src/crypto/x509/root_solaris.go
@@ -6,6 +6,7 @@ package x509
 
 // Possible certificate files; stop after finding one.
 var certFiles = []string{
+	"@PKG_SYSCONFDIR@/openssl/certs/ca-certificates.crt",
 	"/etc/certs/ca-certificates.crt",     // Solaris 11.2+
 	"/etc/ssl/certs/ca-certificates.crt", // Joyent SmartOS
 	"/etc/ssl/cacert.pem",                // OmniOS
@@ -13,5 +14,6 @@ var certFiles = []string{
 
 // Possible directories with certificate files; all will be read.
 var certDirectories = []string{
+	"@PKG_SYSCONFDIR@/openssl/certs",
 	"/etc/certs/CA",
 }
