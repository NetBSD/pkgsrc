$NetBSD: patch-vendor_github.com_containers_common_pkg_config_default__netbsd.go,v 1.1 2023/02/14 00:33:13 tnn Exp $

Disable the virtfs volume driver by default.
Doesn't work yet on NetBSD.

--- vendor/github.com/containers/common/pkg/config/default_netbsd.go.orig	2023-02-14 00:08:51.256531293 +0000
+++ vendor/github.com/containers/common/pkg/config/default_netbsd.go
@@ -0,0 +1,20 @@
+package config
+
+func getDefaultCgroupsMode() string {
+	return "enabled"
+}
+
+func getDefaultLockType() string {
+	return "file"
+}
+
+func getLibpodTmpDir() string {
+	return "@VARBASE@/run/libpod"
+}
+
+// getDefaultMachineVolumes returns default mounted volumes (possibly with env vars, which will be expanded)
+func getDefaultMachineVolumes() []string {
+/* XXXTNN this doesn't work yet. Needs virtio-9p in QEMU */
+//	return []string{"$HOME:$HOME"}
+	return []string{}
+}
