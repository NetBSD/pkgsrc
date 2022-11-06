$NetBSD: patch-vendor_github.com_containers_common_pkg_config_config__darwin.go,v 1.1 2022/11/06 12:39:15 tnn Exp $

Adjust paths. Needed to find gvproxy.

--- vendor/github.com/containers/common/pkg/config/config_darwin.go.orig	2021-12-08 18:41:11
+++ vendor/github.com/containers/common/pkg/config/config_darwin.go
@@ -17,6 +17,8 @@ var defaultHelperBinariesDir = []string{
 }
 
 var defaultHelperBinariesDir = []string{
+	// pkgsrc paths
+	"@PREFIX@/bin",
 	// Homebrew install paths
 	"/usr/local/opt/podman/libexec",
 	"/opt/homebrew/bin",
