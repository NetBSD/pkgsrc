$NetBSD: patch-internal_pkg_disk_free__unix.go,v 1.1 2026/08/30 16:55:23 khorben Exp $

Implement FreeBytes() elsewhere for NetBSD.

--- internal/pkg/disk/free_unix.go.orig	2026-08-26 15:55:27.000000000 +0000
+++ internal/pkg/disk/free_unix.go
@@ -1,7 +1,7 @@
 // Copyright 2026 The Gitea Authors. All rights reserved.
 // SPDX-License-Identifier: MIT
 
-//go:build aix || darwin || dragonfly || freebsd || linux || netbsd || openbsd || solaris
+//go:build aix || darwin || dragonfly || freebsd || linux || openbsd || solaris
 
 package disk
 
