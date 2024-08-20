$NetBSD: patch-vfs_vfstest_write__other.go,v 1.1 2024/08/20 09:25:00 adam Exp $

NetBSD and OpenBSD are Unix-like operating systems.

--- vfs/vfstest/write_other.go.orig	2024-06-14 15:04:51.000000000 +0000
+++ vfs/vfstest/write_other.go
@@ -1,5 +1,5 @@
-//go:build !linux && !darwin && !freebsd && !windows
-// +build !linux,!darwin,!freebsd,!windows
+//go:build !linux && !darwin && !freebsd && !windows && !netbsd && !openbsd
+// +build !linux,!darwin,!freebsd,!windows,!netbsd,!openbsd
 
 package vfstest
 
