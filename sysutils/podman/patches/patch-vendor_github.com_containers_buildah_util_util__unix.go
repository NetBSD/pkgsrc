$NetBSD: patch-vendor_github.com_containers_buildah_util_util__unix.go,v 1.1 2021/09/04 20:28:42 maya Exp $

Add netbsd support (vendor code)

--- vendor/github.com/containers/buildah/util/util_unix.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/containers/buildah/util/util_unix.go
@@ -1,4 +1,4 @@
-// +build linux darwin
+// +build !windows
 
 package util
 
