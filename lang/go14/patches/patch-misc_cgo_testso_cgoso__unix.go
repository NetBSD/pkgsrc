$NetBSD: patch-misc_cgo_testso_cgoso__unix.go,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- misc/cgo/testso/cgoso_unix.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ misc/cgo/testso/cgoso_unix.go
@@ -2,7 +2,7 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-// +build dragonfly freebsd linux netbsd
+// +build dragonfly freebsd linux netbsd solaris
 
 package cgosotest
 
