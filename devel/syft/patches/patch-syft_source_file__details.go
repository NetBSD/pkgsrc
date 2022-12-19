$NetBSD: patch-syft_source_file__details.go,v 1.1 2022/12/19 19:03:09 wiz Exp $

Fix build on NetBSD.
https://github.com/anchore/syft/pull/1412

--- syft/source/file_details.go.orig	2022-12-12 17:55:12.000000000 +0000
+++ syft/source/file_details.go
@@ -1,5 +1,5 @@
-//go:build linux || darwin
-// +build linux darwin
+//go:build linux || darwin || netbsd
+// +build linux darwin netbsd
 
 package source
 
