$NetBSD: patch-src_net_cgo__unix.go,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/net/cgo_unix.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/net/cgo_unix.go
@@ -3,7 +3,7 @@
 // license that can be found in the LICENSE file.
 
 // +build !netgo
-// +build darwin dragonfly freebsd linux netbsd openbsd
+// +build darwin dragonfly freebsd linux netbsd openbsd !solaris
 
 package net
 
