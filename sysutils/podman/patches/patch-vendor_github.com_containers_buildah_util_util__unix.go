$NetBSD: patch-vendor_github.com_containers_buildah_util_util__unix.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Add netbsd support (vendor code)

--- vendor/github.com/containers/buildah/util/util_unix.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/buildah/util/util_unix.go
@@ -1,5 +1,5 @@
-//go:build linux || darwin || freebsd
-// +build linux darwin freebsd
+//go:build linux || darwin || freebsd || netbsd
+// +build linux darwin freebsd netbsd
 
 package util
 
