$NetBSD: patch-vendor_github.com_containers_storage_pkg_homedir_homedir__others.go,v 1.1 2021/09/04 20:28:42 maya Exp $

Add netbsd support (vendor code)

--- vendor/github.com/containers/storage/pkg/homedir/homedir_others.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/homedir/homedir_others.go
@@ -1,4 +1,4 @@
-// +build !linux,!darwin,!freebsd
+// +build !linux,!darwin,!freebsd,!netbsd
 
 package homedir
 
