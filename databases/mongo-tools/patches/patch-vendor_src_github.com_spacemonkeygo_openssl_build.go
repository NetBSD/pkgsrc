$NetBSD: patch-vendor_src_github.com_spacemonkeygo_openssl_build.go,v 1.1 2015/10/21 16:37:22 fhajny Exp $

Simplify lib flags look up via pkg-config.

--- vendor/src/github.com/spacemonkeygo/openssl/build.go.orig	2015-09-25 20:02:24.000000000 +0000
+++ vendor/src/github.com/spacemonkeygo/openssl/build.go
@@ -16,7 +16,5 @@
 
 package openssl
 
-// #cgo linux pkg-config: openssl
-// #cgo windows CFLAGS: -DWIN32_LEAN_AND_MEAN
-// #cgo darwin LDFLAGS: -lssl -lcrypto
+// #cgo pkg-config: openssl
 import "C"
