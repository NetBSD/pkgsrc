$NetBSD: patch-pkg_machine_qemu_options__darwin__arm64.go,v 1.1 2022/11/06 12:39:15 tnn Exp $

Add pkgsrc path for firmware

--- pkg/machine/qemu/options_darwin_arm64.go.orig	2021-12-08 18:41:11.000000000 +0000
+++ pkg/machine/qemu/options_darwin_arm64.go
@@ -45,6 +45,7 @@ func getOvmfDir(imagePath, vmName string
  */
 func getEdk2CodeFd(name string) string {
 	dirs := []string{
+		"@PREFIX@/share/qemu",
 		"/usr/local/share/qemu",
 		"/opt/homebrew/share/qemu",
 	}
