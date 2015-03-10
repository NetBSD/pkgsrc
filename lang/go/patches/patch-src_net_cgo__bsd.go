$NetBSD: patch-src_net_cgo__bsd.go,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- src/net/cgo_bsd.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/net/cgo_bsd.go
@@ -3,7 +3,7 @@
 // license that can be found in the LICENSE file.
 
 // +build !netgo
-// +build darwin dragonfly freebsd solaris
+// +build darwin dragonfly freebsd
 
 package net
 
