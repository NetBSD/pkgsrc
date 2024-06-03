$NetBSD: patch-vendor_github.com_containers_storage_pkg_archive_archive__bsd.go,v 1.2 2024/06/03 02:07:44 maya Exp $

Add NetBSD support (vendor code)
https://github.com/containers/storage/pull/1935

--- vendor/github.com/containers/storage/pkg/archive/archive_bsd.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/archive/archive_bsd.go
@@ -1,5 +1,5 @@
-//go:build freebsd || darwin
-// +build freebsd darwin
+//go:build freebsd || darwin || netbsd
+// +build freebsd darwin netbsd
 
 package archive
 
