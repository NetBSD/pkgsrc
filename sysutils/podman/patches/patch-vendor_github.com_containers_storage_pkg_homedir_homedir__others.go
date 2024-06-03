$NetBSD: patch-vendor_github.com_containers_storage_pkg_homedir_homedir__others.go,v 1.3 2024/06/03 02:07:44 maya Exp $

NetBSD support
https://github.com/containers/storage/pull/1935

--- vendor/github.com/containers/storage/pkg/homedir/homedir_others.go.orig	2024-05-28 22:08:53.504670587 +0000
+++ vendor/github.com/containers/storage/pkg/homedir/homedir_others.go
@@ -1,5 +1,5 @@
-//go:build !linux && !darwin && !freebsd && !windows
-// +build !linux,!darwin,!freebsd,!windows
+//go:build !linux && !darwin && !freebsd && !netbsd && !windows
+// +build !linux,!darwin,!freebsd,!netbsd,!windows
 
 package homedir
 
