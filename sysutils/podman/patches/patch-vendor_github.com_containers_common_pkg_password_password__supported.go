$NetBSD: patch-vendor_github.com_containers_common_pkg_password_password__supported.go,v 1.1 2024/06/03 02:07:44 maya Exp $

NetBSD support
https://github.com/containers/common/pull/2035

--- vendor/github.com/containers/common/pkg/password/password_supported.go.orig	2024-05-28 22:06:36.037026351 +0000
+++ vendor/github.com/containers/common/pkg/password/password_supported.go
@@ -1,4 +1,4 @@
-//go:build linux || darwin || freebsd
+//go:build linux || darwin || freebsd || netbsd
 
 package password
 
