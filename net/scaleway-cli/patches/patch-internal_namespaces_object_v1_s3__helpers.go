$NetBSD: patch-internal_namespaces_object_v1_s3__helpers.go,v 1.1 2026/06/02 12:18:51 leot Exp $

Add support for NetBSD.

--- internal/namespaces/object/v1/s3_helpers.go.orig	2026-06-02 12:12:56.705816075 +0000
+++ internal/namespaces/object/v1/s3_helpers.go
@@ -1,4 +1,4 @@
-//go:build darwin || linux || windows
+//go:build darwin || linux || netbsd || windows
 
 package object
 
