$NetBSD: patch-internal_namespaces_object_v1_custom__disabled.go,v 1.1 2026/06/02 12:18:51 leot Exp $

Add support for NetBSD.

--- internal/namespaces/object/v1/custom_disabled.go.orig	2026-06-02 12:12:51.831965830 +0000
+++ internal/namespaces/object/v1/custom_disabled.go
@@ -1,4 +1,4 @@
-//go:build !(darwin || linux || windows)
+//go:build !(darwin || linux || netbsd || windows)
 
 package object
 
