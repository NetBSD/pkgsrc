$NetBSD: patch-vfs_vfstest_write__unix.go,v 1.1 2020/05/28 11:13:17 leot Exp $

NetBSD and OpenBSD are Unix-like operating systems.

--- vfs/vfstest/write_unix.go.orig	2020-05-27 16:31:10.000000000 +0000
+++ vfs/vfstest/write_unix.go
@@ -1,4 +1,4 @@
-// +build linux darwin freebsd
+// +build linux darwin freebsd netbsd openbsd
 
 package vfstest
 
