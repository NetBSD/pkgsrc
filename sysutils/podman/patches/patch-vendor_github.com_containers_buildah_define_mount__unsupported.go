$NetBSD: patch-vendor_github.com_containers_buildah_define_mount__unsupported.go,v 1.2 2024/06/03 02:07:44 maya Exp $

Add NetBSD support (vendor code)

https://github.com/containers/buildah/pull/5559

--- vendor/github.com/containers/buildah/define/mount_unsupported.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/buildah/define/mount_unsupported.go
@@ -1,5 +1,5 @@
-//go:build darwin || windows
-// +build darwin windows
+//go:build darwin || windows || netbsd
+// +build darwin windows netbsd
 
 package define
 
