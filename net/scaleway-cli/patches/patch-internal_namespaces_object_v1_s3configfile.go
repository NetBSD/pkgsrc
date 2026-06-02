$NetBSD: patch-internal_namespaces_object_v1_s3configfile.go,v 1.1 2026/06/02 12:18:51 leot Exp $

Add support for NetBSD.

--- internal/namespaces/object/v1/s3configfile.go.orig	2026-06-02 12:13:02.515869564 +0000
+++ internal/namespaces/object/v1/s3configfile.go
@@ -1,4 +1,4 @@
-//go:build darwin || linux || windows
+//go:build darwin || linux || netbsd || windows
 
 package object
 
