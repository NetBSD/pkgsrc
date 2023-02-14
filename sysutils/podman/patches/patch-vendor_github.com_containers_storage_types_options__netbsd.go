$NetBSD: patch-vendor_github.com_containers_storage_types_options__netbsd.go,v 1.1 2023/02/14 00:33:13 tnn Exp $

Add NetBSD support (vendor code)

--- vendor/github.com/containers/storage/types/options_netbsd.go.orig	2023-02-13 23:02:15.105475801 +0000
+++ vendor/github.com/containers/storage/types/options_netbsd.go
@@ -0,0 +1,14 @@
+package types
+
+const (
+	// these are default path for run and graph root for rootful users
+	// for rootless path is constructed via getRootlessStorageOpts
+	defaultRunRoot   string = "@VARBASE@/run/containers/storage"
+	defaultGraphRoot string = "@VARBASE@/db/containers/storage"
+	SystemConfigFile        = "@PREFIX@/share/containers/storage.conf"
+)
+
+// defaultConfigFile path to the system wide storage.conf file
+var (
+	defaultOverrideConfigFile = "@PREFIX@/etc/containers/storage.conf"
+)
