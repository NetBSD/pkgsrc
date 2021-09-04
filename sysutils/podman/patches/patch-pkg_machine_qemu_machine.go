$NetBSD: patch-pkg_machine_qemu_machine.go,v 1.1 2021/09/04 20:28:42 maya Exp $

Use an expected path typical for pkgsrc.

--- pkg/machine/qemu/machine.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ pkg/machine/qemu/machine.go
@@ -1,4 +1,4 @@
-// +build amd64,linux arm64,linux amd64,darwin arm64,darwin
+// +build amd64,!windows arm64,!windows
 
 package qemu
 
@@ -624,7 +624,7 @@ func (v *MachineVM) startHostNetworking(
 	binary, err := exec.LookPath(machine.ForwarderBinaryName)
 	if errors.Is(err, exec.ErrNotFound) {
 		// Nothing was found, so now check /usr/libexec, else error out
-		binary = filepath.Join("/usr/libexec/podman/", machine.ForwarderBinaryName)
+		binary = filepath.Join("@PREFIX@/bin", machine.ForwarderBinaryName)
 		if _, err := os.Stat(binary); err != nil {
 			return err
 		}
