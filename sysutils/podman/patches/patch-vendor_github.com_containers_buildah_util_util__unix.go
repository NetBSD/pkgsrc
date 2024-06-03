$NetBSD: patch-vendor_github.com_containers_buildah_util_util__unix.go,v 1.3 2024/06/03 02:07:44 maya Exp $

Add netbsd support (vendor code)
https://github.com/containers/buildah/pull/5559

--- vendor/github.com/containers/buildah/util/util_unix.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/buildah/util/util_unix.go
@@ -1,5 +1,5 @@
-//go:build linux || darwin || freebsd
-// +build linux darwin freebsd
+//go:build linux || darwin || freebsd || netbsd
+// +build linux darwin freebsd netbsd
 
 package util
 
