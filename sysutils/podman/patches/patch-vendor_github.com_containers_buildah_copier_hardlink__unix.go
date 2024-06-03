$NetBSD: patch-vendor_github.com_containers_buildah_copier_hardlink__unix.go,v 1.1 2024/06/03 02:07:44 maya Exp $

NetBSD support
https://github.com/containers/buildah/pull/5559

--- vendor/github.com/containers/buildah/copier/hardlink_unix.go.orig	2024-05-28 22:30:37.796669657 +0000
+++ vendor/github.com/containers/buildah/copier/hardlink_unix.go
@@ -1,5 +1,5 @@
-//go:build linux || darwin || freebsd
-// +build linux darwin freebsd
+//go:build linux || darwin || freebsd || netbsd
+// +build linux darwin freebsd netbsd
 
 package copier
 
