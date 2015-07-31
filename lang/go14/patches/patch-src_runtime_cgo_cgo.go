$NetBSD: patch-src_runtime_cgo_cgo.go,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/runtime/cgo/cgo.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/runtime/cgo/cgo.go
@@ -21,6 +21,7 @@ package cgo
 #cgo windows LDFLAGS: -lm -mthreads
 
 #cgo CFLAGS: -Wall -Werror
+#cgo solaris CFLAGS: -D_POSIX_PTHREAD_SEMANTICS
 
 */
 import "C"
