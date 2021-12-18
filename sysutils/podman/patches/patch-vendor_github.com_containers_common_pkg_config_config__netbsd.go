$NetBSD: patch-vendor_github.com_containers_common_pkg_config_config__netbsd.go,v 1.2 2021/12/18 18:11:48 leot Exp $

Add netbsd support (vendor code)

--- vendor/github.com/containers/common/pkg/config/config_netbsd.go.orig	2021-10-01 19:59:28.975404283 +0000
+++ vendor/github.com/containers/common/pkg/config/config_netbsd.go
@@ -0,0 +1,22 @@
+package config
+
+import (
+	"os"
+)
+
+// podman remote clients on darwin cannot use unshare.isRootless() to determine the configuration file locations.
+func customConfigFile() (string, error) {
+	if path, found := os.LookupEnv("CONTAINERS_CONF"); found {
+		return path, nil
+	}
+	return rootlessConfigPath()
+}
+
+func ifRootlessConfigPath() (string, error) {
+	return rootlessConfigPath()
+}
+
+var defaultHelperBinariesDir = []string{
+	// pkgsrc paths
+	"@PREFIX@/bin",
+}
