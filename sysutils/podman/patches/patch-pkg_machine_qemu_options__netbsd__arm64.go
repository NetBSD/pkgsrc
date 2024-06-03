$NetBSD: patch-pkg_machine_qemu_options__netbsd__arm64.go,v 1.2 2024/06/03 02:07:44 maya Exp $

NetBSD support.

--- pkg/machine/qemu/options_netbsd_arm64.go.orig	2024-05-28 23:58:18.721596493 +0000
+++ pkg/machine/qemu/options_netbsd_arm64.go
@@ -0,0 +1,50 @@
+package qemu
+
+import (
+	"os"
+	"os/exec"
+	"path/filepath"
+)
+
+var (
+	QemuCommand = "qemu-system-aarch64"
+)
+
+func (v *QEMUStubber) addArchOptions(_ *setNewMachineCMDOpts) []string {
+	ovmfDir := getOvmfDir(v.ImagePath.GetPath(), v.Name)
+	opts := []string{
+		"-accel", "tcg",
+		"-cpu", "cortex-a57",
+		"-M", "virt",
+		"-drive", "file=" + getEdk2CodeFd("edk2-aarch64-code.fd") + ",if=pflash,format=raw,readonly=on",
+		"-drive", "file=" + ovmfDir + ",if=pflash,format=raw"}
+	return opts
+}
+
+func (v *QEMUStubber) prepare() error {
+	ovmfDir := getOvmfDir(v.ImagePath.GetPath(), v.Name)
+	cmd := []string{"/bin/dd", "if=/dev/zero", "conv=sync", "bs=1m", "count=64", "of=" + ovmfDir}
+	return exec.Command(cmd[0], cmd[1:]...).Run()
+}
+
+func (v *QEMUStubber) archRemovalFiles() []string {
+	ovmDir := getOvmfDir(v.ImagePath.GetPath(), v.Name)
+	return []string{ovmDir}
+}
+
+func getOvmfDir(imagePath, vmName string) string {
+	return filepath.Join(filepath.Dir(imagePath), vmName+"_ovmf_vars.fd")
+}
+
+func getEdk2CodeFd(name string) string {
+	dirs := []string{
+		"@PREFIX@/share/qemu",
+	}
+	for _, dir := range dirs {
+		fullpath := filepath.Join(dir, name)
+		if _, err := os.Stat(fullpath); err == nil {
+			return fullpath
+		}
+	}
+	return name
+}
