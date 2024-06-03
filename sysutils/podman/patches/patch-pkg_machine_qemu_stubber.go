$NetBSD: patch-pkg_machine_qemu_stubber.go,v 1.1 2024/06/03 02:07:44 maya Exp $

Add NetBSD support

--- pkg/machine/qemu/stubber.go.orig	2024-05-29 00:07:05.307241824 +0000
+++ pkg/machine/qemu/stubber.go
@@ -1,4 +1,4 @@
-//go:build linux || freebsd
+//go:build linux || freebsd || netbsd
 
 package qemu
 
