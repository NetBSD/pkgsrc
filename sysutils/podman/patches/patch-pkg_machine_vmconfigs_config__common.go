$NetBSD: patch-pkg_machine_vmconfigs_config__common.go,v 1.1 2024/06/03 02:07:44 maya Exp $

--- pkg/machine/vmconfigs/config_common.go.orig	2024-05-29 00:05:33.264766331 +0000
+++ pkg/machine/vmconfigs/config_common.go
@@ -1,4 +1,4 @@
-//go:build linux || freebsd
+//go:build linux || freebsd || netbsd
 
 package vmconfigs
 
