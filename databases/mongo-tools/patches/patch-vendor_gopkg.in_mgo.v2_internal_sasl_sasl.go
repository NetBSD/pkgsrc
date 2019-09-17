$NetBSD: patch-vendor_gopkg.in_mgo.v2_internal_sasl_sasl.go,v 1.1 2019/09/17 08:21:01 adam Exp $

Simplify lib flags look up via pkg-config.

--- vendor/gopkg.in/mgo.v2/internal/sasl/sasl.go.orig	2015-09-25 20:02:24.000000000 +0000
+++ vendor/gopkg.in/mgo.v2/internal/sasl/sasl.go
@@ -7,7 +7,7 @@
 
 package sasl
 
-// #cgo LDFLAGS: -lsasl2
+// #cgo pkg-config: libsasl2
 //
 // struct sasl_conn {};
 //
