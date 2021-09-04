$NetBSD: patch-pkg_util_utils__supported.go,v 1.1 2021/09/04 20:28:42 maya Exp $

https://github.com/containers/podman/pull/11434

--- pkg/util/utils_supported.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ pkg/util/utils_supported.go
@@ -1,4 +1,4 @@
-// +build linux darwin
+// +build !windows
 
 package util
 
