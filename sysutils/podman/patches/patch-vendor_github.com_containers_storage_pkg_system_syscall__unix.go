$NetBSD: patch-vendor_github.com_containers_storage_pkg_system_syscall__unix.go,v 1.1 2021/12/18 18:11:48 leot Exp $

Add NetBSD support.

--- vendor/github.com/containers/storage/pkg/system/syscall_unix.go.orig	2021-12-08 18:41:11.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/system/syscall_unix.go
@@ -1,4 +1,4 @@
-// +build linux freebsd darwin
+// +build linux freebsd darwin netbsd
 
 package system
 
