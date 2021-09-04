$NetBSD: patch-pkg_machine_qemu_options__netbsd__amd64.go,v 1.1 2021/09/04 20:28:42 maya Exp $

Add netbsd/amd64 support - uses nvmm

--- pkg/machine/qemu/options_netbsd_amd64.go.orig	2021-09-04 12:43:04.031906656 +0000
+++ pkg/machine/qemu/options_netbsd_amd64.go
@@ -0,0 +1,20 @@
+package qemu
+
+var (
+	QemuCommand = "qemu-system-x86_64"
+)
+
+func (v *MachineVM) addArchOptions() []string {
+	opts := []string{
+		"-accel", "nvmm",
+	}
+	return opts
+}
+
+func (v *MachineVM) prepare() error {
+	return nil
+}
+
+func (v *MachineVM) archRemovalFiles() []string {
+	return []string{}
+}
