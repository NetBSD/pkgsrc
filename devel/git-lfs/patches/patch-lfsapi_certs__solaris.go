$NetBSD: patch-lfsapi_certs__solaris.go,v 1.1 2018/09/14 09:26:18 fhajny Exp $

Add support for SunOS.

--- lfsapi/certs_solaris.go.orig	2018-09-14 09:10:49.926008484 +0000
+++ lfsapi/certs_solaris.go
@@ -0,0 +1,8 @@
+package lfsapi
+
+import "crypto/x509"
+
+func appendRootCAsForHostFromPlatform(pool *x509.CertPool, host string) *x509.CertPool {
+	// Do nothing, use golang default
+	return pool
+}
