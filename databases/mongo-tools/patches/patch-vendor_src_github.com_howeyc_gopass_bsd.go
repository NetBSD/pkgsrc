$NetBSD: patch-vendor_src_github.com_howeyc_gopass_bsd.go,v 1.1 2015/10/21 16:37:22 fhajny Exp $

The BSD implementation seems to work fine for SunOS.

--- vendor/src/github.com/howeyc/gopass/bsd.go.orig	2015-04-01 22:40:18.000000000 +0000
+++ vendor/src/github.com/howeyc/gopass/bsd.go
@@ -1,4 +1,4 @@
-// +build freebsd openbsd netbsd
+// +build freebsd openbsd netbsd solaris
 
 package gopass
 
