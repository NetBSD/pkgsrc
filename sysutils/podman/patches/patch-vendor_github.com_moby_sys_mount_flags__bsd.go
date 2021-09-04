$NetBSD: patch-vendor_github.com_moby_sys_mount_flags__bsd.go,v 1.1 2021/09/04 20:28:42 maya Exp $

Add netbsd support (vendor code)

--- vendor/github.com/moby/sys/mount/flags_bsd.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/moby/sys/mount/flags_bsd.go
@@ -1,4 +1,4 @@
-// +build freebsd openbsd
+// +build freebsd openbsd netbsd
 
 package mount
 
