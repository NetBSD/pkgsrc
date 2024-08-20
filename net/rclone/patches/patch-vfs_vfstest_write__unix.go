$NetBSD: patch-vfs_vfstest_write__unix.go,v 1.2 2024/08/20 09:25:00 adam Exp $

NetBSD and OpenBSD are Unix-like operating systems.

--- vfs/vfstest/write_unix.go.orig	2024-06-14 15:04:51.000000000 +0000
+++ vfs/vfstest/write_unix.go
@@ -1,4 +1,4 @@
-//go:build linux || darwin || freebsd
+//go:build linux || darwin || freebsd || netbsd || openbsd
 
 package vfstest
 
