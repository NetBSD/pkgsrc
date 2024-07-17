$NetBSD: patch-runtime_battery_battery__solaris.go,v 1.1 2024/07/17 06:23:56 pin Exp $

Compile on Solaris.

--- runtime/battery/battery_solaris.go.orig	2023-04-11 15:17:25.347000229 +0000
+++ runtime/battery/battery_solaris.go
@@ -0,0 +1,9 @@
+package battery
+
+import (
+	"errors"
+)
+
+func Get() (*Info, error) {
+	return nil, errors.New("Unable to parse battery percentage")
+}
