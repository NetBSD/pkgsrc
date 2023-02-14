$NetBSD: patch-vendor_github.com_containers_common_pkg_config_config__darwin.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Adjust paths. Needed to find gvproxy.

--- vendor/github.com/containers/common/pkg/config/config_darwin.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/common/pkg/config/config_darwin.go
@@ -29,6 +29,8 @@ func ifRootlessConfigPath() (string, err
 }
 
 var defaultHelperBinariesDir = []string{
+	// pkgsrc paths
+	"@PREFIX@/bin",
 	// Homebrew install paths
 	"/usr/local/opt/podman/libexec",
 	"/opt/homebrew/bin",
