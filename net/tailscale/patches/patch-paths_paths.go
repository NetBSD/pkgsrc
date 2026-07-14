$NetBSD: patch-paths_paths.go,v 1.1 2026/07/14 20:43:31 schmonz Exp $

Follow hier(7).

--- paths/paths.go.orig	2026-07-02 14:59:26.000000000 -0400
+++ paths/paths.go
@@ -25,28 +25,7 @@
 	if runtime.GOOS == "windows" {
 		return `\\.\pipe\ProtectedPrefix\Administrators\Tailscale\tailscaled`
 	}
-	if runtime.GOOS == "darwin" {
-		return "/var/run/tailscaled.socket"
-	}
-	if runtime.GOOS == "plan9" {
-		return "/srv/tailscaled.sock"
-	}
-	switch distro.Get() {
-	case distro.Synology:
-		if distro.DSMVersion() == 6 {
-			return "/var/packages/Tailscale/etc/tailscaled.sock"
-		}
-		// DSM 7 (and higher? or failure to detect.)
-		return "/var/packages/Tailscale/var/tailscaled.sock"
-	case distro.Gokrazy:
-		return "/perm/tailscaled/tailscaled.sock"
-	case distro.QNAP:
-		return "/tmp/tailscale/tailscaled.sock"
-	}
-	if fi, err := os.Stat("/var/run"); err == nil && fi.IsDir() {
-		return "/var/run/tailscale/tailscaled.sock"
-	}
-	return "tailscaled.sock"
+	return "@VARBASE@/run/tailscale/tailscaled.sock"
 }
 
 // Overridden in init by OS-specific files.
