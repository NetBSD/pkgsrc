$NetBSD: patch-vendor_src_gopkg.in_mgo.v2_internal_sasl_sasl.go,v 1.1 2015/10/21 16:37:22 fhajny Exp $

Simplify lib flags look up via pkg-config.

--- vendor/src/gopkg.in/mgo.v2/internal/sasl/sasl.go.orig	2015-09-25 20:02:24.000000000 +0000
+++ vendor/src/gopkg.in/mgo.v2/internal/sasl/sasl.go
@@ -7,7 +7,7 @@
 
 package sasl
 
-// #cgo LDFLAGS: -lsasl2
+// #cgo pkg-config: libsasl2
 //
 // struct sasl_conn {};
 //
