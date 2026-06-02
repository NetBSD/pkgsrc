$NetBSD: patch-internal_namespaces_object_v1_custom__config__get.go,v 1.1 2026/06/02 12:18:51 leot Exp $

Add support for NetBSD.

--- internal/namespaces/object/v1/custom_config_get.go.orig	2026-06-02 12:12:41.836912672 +0000
+++ internal/namespaces/object/v1/custom_config_get.go
@@ -1,4 +1,4 @@
-//go:build darwin || linux || windows
+//go:build darwin || linux || netbsd || windows
 
 package object
 
