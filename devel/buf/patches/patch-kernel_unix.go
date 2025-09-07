$NetBSD: patch-kernel_unix.go,v 1.1 2025/09/07 18:29:25 maya Exp $

NetBSD support

--- ../github.com/docker/docker@v27.3.1+incompatible/pkg/parsers/kernel/kernel_unix.go.orig	2025-09-07 01:54:06.242291399 +0000
+++ ../github.com/docker/docker@v27.3.1+incompatible/pkg/parsers/kernel/kernel_unix.go
@@ -1,4 +1,4 @@
-//go:build linux || freebsd || openbsd
+//go:build linux || freebsd || openbsd || netbsd
 
 package kernel // import "github.com/docker/docker/pkg/parsers/kernel"
 
