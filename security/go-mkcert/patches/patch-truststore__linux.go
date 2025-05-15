$NetBSD: patch-truststore__linux.go,v 1.1 2025/05/15 19:29:16 schmonz Exp $

Support pkgsrc OpenSSL certsdir.

--- truststore_linux.go.orig	2022-04-26 17:37:25.000000000 +0000
+++ truststore_linux.go
@@ -45,6 +45,9 @@ func init() {
 	} else if pathExists("/usr/share/pki/trust/anchors") {
 		SystemTrustFilename = "/usr/share/pki/trust/anchors/%s.pem"
 		SystemTrustCommand = []string{"update-ca-certificates"}
+	} else if pathExists("@SSLCERTS@") {
+		SystemTrustFilename = "@SSLCERTS@/%s.pem"
+		SystemTrustCommand = []string{"@PREFIX@/libexec/rehash-mozilla-rootcerts", "@SSLCERTS@"}
 	}
 }
 
