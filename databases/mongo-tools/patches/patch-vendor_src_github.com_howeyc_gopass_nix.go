$NetBSD: patch-vendor_src_github.com_howeyc_gopass_nix.go,v 1.1 2017/05/03 16:49:54 fhajny Exp $

Builds on SunOS.

--- vendor/src/github.com/howeyc/gopass/nix.go.orig	2016-12-29 22:33:41.000000000 +0000
+++ vendor/src/github.com/howeyc/gopass/nix.go
@@ -1,4 +1,4 @@
-// +build linux darwin freebsd netbsd openbsd
+// +build linux darwin freebsd netbsd openbsd solaris
 
 package gopass
 
