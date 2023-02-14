$NetBSD: patch-pkg_machine_ignition__netbsd.go,v 1.1 2023/02/14 00:33:13 tnn Exp $

add netbsd support

--- pkg/machine/ignition_netbsd.go.orig	2023-02-13 23:37:08.090532081 +0000
+++ pkg/machine/ignition_netbsd.go
@@ -0,0 +1,17 @@
+//go:build netbsd
+// +build netbsd
+
+package machine
+
+import (
+	"os"
+	"strings"
+)
+
+func getLocalTimeZone() (string, error) {
+	tzPath, err := os.Readlink("/etc/localtime")
+	if err != nil {
+		return "", err
+	}
+	return strings.TrimPrefix(tzPath, "/usr/share/zoneinfo/"), nil
+}
