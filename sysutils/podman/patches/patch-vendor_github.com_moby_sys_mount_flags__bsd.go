$NetBSD: patch-vendor_github.com_moby_sys_mount_flags__bsd.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Add netbsd support (vendor code)

--- vendor/github.com/moby/sys/mount/flags_bsd.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/moby/sys/mount/flags_bsd.go
@@ -1,5 +1,5 @@
-//go:build freebsd || openbsd
-// +build freebsd openbsd
+//go:build freebsd || openbsd || netbsd
+// +build freebsd openbsd netbsd
 
 package mount
 
