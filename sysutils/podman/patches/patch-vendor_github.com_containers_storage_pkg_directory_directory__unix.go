$NetBSD: patch-vendor_github.com_containers_storage_pkg_directory_directory__unix.go,v 1.3 2024/06/03 02:07:44 maya Exp $

Add netbsd support (vendor code)
https://github.com/containers/storage/pull/1935

--- vendor/github.com/containers/storage/pkg/directory/directory_unix.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/directory/directory_unix.go
@@ -1,5 +1,5 @@
-//go:build linux || darwin || freebsd || solaris
-// +build linux darwin freebsd solaris
+//go:build linux || darwin || freebsd || solaris || netbsd
+// +build !windows
 
 package directory
 
