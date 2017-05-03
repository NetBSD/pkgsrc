$NetBSD: patch-vendor_src_github.com_spacemonkeygo_openssl_build.go,v 1.2 2017/05/03 16:49:54 fhajny Exp $

Simplify lib flags look up via pkg-config.

--- vendor/src/github.com/spacemonkeygo/openssl/build.go.orig	2016-12-29 22:33:41.000000000 +0000
+++ vendor/src/github.com/spacemonkeygo/openssl/build.go
@@ -16,9 +16,5 @@
 
 package openssl
 
-// #cgo linux pkg-config: openssl
-// #cgo windows CFLAGS: -DWIN32_LEAN_AND_MEAN
-// #cgo windows LDFLAGS: -lcrypt32
-// #cgo darwin CFLAGS: -Wno-deprecated-declarations
-// #cgo darwin LDFLAGS: -lssl -lcrypto -framework CoreFoundation -framework Foundation -framework Security
+// #cgo pkg-config: openssl
 import "C"
