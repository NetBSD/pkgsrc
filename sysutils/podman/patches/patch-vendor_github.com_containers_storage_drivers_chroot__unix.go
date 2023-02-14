$NetBSD: patch-vendor_github.com_containers_storage_drivers_chroot__unix.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Add netbsd support (vendor code)

--- vendor/github.com/containers/storage/drivers/chroot_unix.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/storage/drivers/chroot_unix.go
@@ -1,5 +1,5 @@
-//go:build linux || darwin || freebsd || solaris
-// +build linux darwin freebsd solaris
+//go:build linux || darwin || freebsd || solaris || netbsd
+// +build !windows
 
 package graphdriver
 
