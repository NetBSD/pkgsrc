$NetBSD: patch-utils_utils__supported.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Add NetBSD support

--- utils/utils_supported.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ utils/utils_supported.go
@@ -1,5 +1,5 @@
-//go:build linux || darwin || freebsd
-// +build linux darwin freebsd
+//go:build linux || darwin || freebsd || netbsd
+// +build linux darwin freebsd netbsd
 
 package utils
 
