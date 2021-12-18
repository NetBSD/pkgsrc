$NetBSD: patch-utils_utils__supported.go,v 1.1 2021/12/18 18:11:48 leot Exp $

Add NetBSD support

--- utils/utils_supported.go.orig	2021-09-30 18:44:31.000000000 +0000
+++ utils/utils_supported.go
@@ -1,4 +1,4 @@
-// +build linux darwin
+// +build linux darwin netbsd
 
 package utils
 
