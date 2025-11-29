$NetBSD: patch-vfs_vfstest_write__other.go,v 1.2 2025/11/29 17:15:36 adam Exp $

NetBSD and OpenBSD are Unix-like operating systems.

--- vfs/vfstest/write_other.go.orig	2025-11-21 17:10:17.000000000 +0000
+++ vfs/vfstest/write_other.go
@@ -1,4 +1,4 @@
-//go:build !linux && !darwin && !freebsd && !windows
+//go:build !linux && !darwin && !freebsd && !windows && !netbsd && !openbsd
 
 package vfstest
 
