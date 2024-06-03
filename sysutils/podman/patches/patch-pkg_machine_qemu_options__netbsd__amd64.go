$NetBSD: patch-pkg_machine_qemu_options__netbsd__amd64.go,v 1.2 2024/06/03 02:07:44 maya Exp $

Add netbsd/amd64 support - uses nvmm

--- pkg/machine/qemu/options_netbsd_amd64.go.orig	2024-05-28 23:58:18.698452676 +0000
+++ pkg/machine/qemu/options_netbsd_amd64.go
@@ -0,0 +1,12 @@
+package qemu
+
+var (
+	QemuCommand = "qemu-system-x86_64"
+)
+
+func (v *QEMUStubber) addArchOptions(_ *setNewMachineCMDOpts) []string {
+	opts := []string{
+		"-accel", "nvmm",
+	}
+	return opts
+}
