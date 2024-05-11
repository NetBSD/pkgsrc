$NetBSD: patch-.._.._github.com_barasher_go-exiftool@v1.10.0_platform__netbsd.go,v 1.1 2024/05/11 10:14:14 wiz Exp $

Add NetBSD support.
https://github.com/barasher/go-exiftool/pull/70

--- ../../github.com/barasher/go-exiftool@v1.10.0/platform_netbsd.go.orig	2024-05-10 17:36:42.110169501 +0000
+++ ../../github.com/barasher/go-exiftool@v1.10.0/platform_netbsd.go
@@ -0,0 +1,7 @@
+package exiftool
+
+var readyToken = []byte("{ready}\n")
+
+const writeMetadataSuccessToken = "image files updated\n"
+
+var exiftoolBinary = "exiftool"
