$NetBSD: patch-vendor_github.com_containers_buildah_util_util__uint64.go,v 1.1 2021/09/04 20:28:42 maya Exp $

Add netbsd support

--- vendor/github.com/containers/buildah/util/util_uint64.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ vendor/github.com/containers/buildah/util/util_uint64.go
@@ -1,4 +1,4 @@
-// +build linux,!mips,!mipsle,!mips64,!mips64le
+// +build linux,!mips,!mipsle,!mips64,!mips64le netbsd
 
 package util
 
