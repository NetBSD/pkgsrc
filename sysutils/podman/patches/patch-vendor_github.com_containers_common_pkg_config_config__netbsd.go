$NetBSD: patch-vendor_github.com_containers_common_pkg_config_config__netbsd.go,v 1.3 2023/02/14 00:33:13 tnn Exp $

Add netbsd support (vendor code)

--- vendor/github.com/containers/common/pkg/config/config_netbsd.go.orig	2023-02-13 22:47:42.194453410 +0000
+++ vendor/github.com/containers/common/pkg/config/config_netbsd.go
@@ -0,0 +1,34 @@
+package config
+
+import (
+	"os"
+)
+
+const (
+	// OverrideContainersConfig holds the default config path overridden by the root user
+	OverrideContainersConfig = "@PREFIX@/etc/" + _configPath
+
+	// DefaultContainersConfig holds the default containers config path
+	DefaultContainersConfig = "@PREFIX@/share/" + _configPath
+
+	// DefaultSignaturePolicyPath is the default value for the
+	// policy.json file.
+	DefaultSignaturePolicyPath = "@PREFIX@/etc/containers/policy.json"
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
