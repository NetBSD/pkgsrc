$NetBSD: patch-hostinfo_hostinfo__darwin.go,v 1.1 2026/07/14 20:43:31 schmonz Exp $

Accurately report older macOS versions.

--- hostinfo/hostinfo_darwin.go.orig	2026-07-02 18:59:26.000000000 +0000
+++ hostinfo/hostinfo_darwin.go
@@ -7,7 +7,9 @@ package hostinfo
 
 import (
 	"os"
+	"os/exec"
 	"path/filepath"
+	"strings"
 
 	"golang.org/x/sys/unix"
 )
@@ -27,11 +29,15 @@ func packageTypeDarwin() string {
 	return filepath.Base(exe)
 }
 
-// Returns the marketing version (e.g., "15.0.1" or "26.0.0")
+// Returns the marketing version (e.g., "10.9.5" or "26.0.0")
 func osVersionDarwin() string {
 	version, err := unix.Sysctl("kern.osproductversion")
-	if err != nil {
-		return ""
+	if err == nil && version != "" {
+		return version
 	}
-	return version
+	out, err := exec.Command("sw_vers", "-productVersion").Output()
+	if err == nil {
+		return strings.TrimSpace(string(out))
+	}
+	return ""
 }
