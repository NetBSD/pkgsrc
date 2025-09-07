$NetBSD: patch-layer_unix.go,v 1.1 2025/09/07 18:29:25 maya Exp $

NetBSD support

--- ../github.com/docker/docker@v27.3.1+incompatible/layer/layer_unix.go.orig	2025-09-07 01:54:15.368620593 +0000
+++ ../github.com/docker/docker@v27.3.1+incompatible/layer/layer_unix.go
@@ -1,4 +1,4 @@
-//go:build linux || freebsd || darwin || openbsd
+//go:build linux || freebsd || darwin || openbsd || netbsd
 
 package layer // import "github.com/docker/docker/layer"
 
