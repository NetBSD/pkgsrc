$NetBSD: patch-src_crypto_x509_root__solaris.go,v 1.1 2021/08/22 13:10:18 bsiegert Exp $

Use pkgsrc certificates by default.

--- src/crypto/x509/root_solaris.go.orig	2021-03-11 17:14:31.000000000 +0000
+++ src/crypto/x509/root_solaris.go
@@ -6,6 +6,7 @@ package x509
 
 // Possible certificate files; stop after finding one.
 var certFiles = []string{
+	"@PKG_SYSCONFDIR@/openssl/certs/ca-certificates.crt",
 	"/etc/certs/ca-certificates.crt",     // Solaris 11.2+
 	"/etc/ssl/certs/ca-certificates.crt", // Joyent SmartOS
 	"/etc/ssl/cacert.pem",                // OmniOS
@@ -14,5 +15,6 @@ var certFiles = []string{
 // Possible directories with certificate files; stop after successfully
 // reading at least one file from a directory.
 var certDirectories = []string{
+	"@PKG_SYSCONFDIR@/openssl/certs",
 	"/etc/certs/CA",
 }
