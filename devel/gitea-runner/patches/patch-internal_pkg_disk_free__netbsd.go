$NetBSD: patch-internal_pkg_disk_free__netbsd.go,v 1.1 2026/08/30 16:55:23 khorben Exp $

Implement FreeBytes() for NetBSD.

--- internal/pkg/disk/free_netbsd.go.orig	2026-08-30 16:45:49.767301268 +0000
+++ internal/pkg/disk/free_netbsd.go
@@ -0,0 +1,17 @@
+// Copyright 2026 The Gitea Authors. All rights reserved.
+// SPDX-License-Identifier: MIT
+
+//go:build netbsd
+
+package disk
+
+import "golang.org/x/sys/unix"
+
+// FreeBytes reports the space available to an unprivileged user on the volume holding path.
+func FreeBytes(path string) (uint64, error) {
+	var stat unix.Statvfs_t
+	if err := unix.Statvfs1(path, &stat, unix.ST_WAIT); err != nil {
+		return 0, err
+	}
+	return uint64(stat.Bavail) * uint64(stat.Bsize), nil
+}
