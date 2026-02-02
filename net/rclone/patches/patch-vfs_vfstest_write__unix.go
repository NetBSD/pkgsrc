$NetBSD: patch-vfs_vfstest_write__unix.go,v 1.3 2026/02/02 08:49:57 adam Exp $

NetBSD and OpenBSD are Unix-like operating systems.

--- vfs/vfstest/write_unix.go.orig	2026-01-30 20:53:56.000000000 +0000
+++ vfs/vfstest/write_unix.go
@@ -1,4 +1,4 @@
-//go:build linux || darwin || freebsd || openbsd
+//go:build linux || darwin || freebsd || netbsd || openbsd
 
 package vfstest
 
