$NetBSD: patch-internal_namespaces_object_v1_custom__bucket.go,v 1.1 2026/06/02 12:18:51 leot Exp $

Add support for NetBSD.

--- internal/namespaces/object/v1/custom_bucket.go.orig	2026-06-02 12:12:25.090117011 +0000
+++ internal/namespaces/object/v1/custom_bucket.go
@@ -1,4 +1,4 @@
-//go:build darwin || linux || windows
+//go:build darwin || linux || netbsd || windows
 
 package object
 
