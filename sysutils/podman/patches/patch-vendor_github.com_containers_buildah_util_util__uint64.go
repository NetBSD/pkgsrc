$NetBSD: patch-vendor_github.com_containers_buildah_util_util__uint64.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Add netbsd support

--- vendor/github.com/containers/buildah/util/util_uint64.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/buildah/util/util_uint64.go
@@ -1,5 +1,5 @@
-//go:build (linux && !mips && !mipsle && !mips64 && !mips64le) || freebsd
-// +build linux,!mips,!mipsle,!mips64,!mips64le freebsd
+//go:build (linux && !mips && !mipsle && !mips64 && !mips64le) || freebsd || netbsd
+// +build linux,!mips,!mipsle,!mips64,!mips64le freebsd netbsd
 
 package util
 
