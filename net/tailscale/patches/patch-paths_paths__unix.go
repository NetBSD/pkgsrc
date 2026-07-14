$NetBSD: patch-paths_paths__unix.go,v 1.1 2026/07/14 20:43:31 schmonz Exp $

Follow hier(7).

--- paths/paths_unix.go.orig	2026-07-02 18:59:26.000000000 +0000
+++ paths/paths_unix.go
@@ -24,18 +24,7 @@ func statePath() string {
 	if runtime.GOOS == "linux" && distro.Get() == distro.JetKVM {
 		return "/userdata/tailscale/var/tailscaled.state"
 	}
-	switch runtime.GOOS {
-	case "linux", "illumos", "solaris":
-		return "/var/lib/tailscale/tailscaled.state"
-	case "freebsd", "openbsd", "netbsd":
-		return "/var/db/tailscale/tailscaled.state"
-	case "darwin":
-		return "/Library/Tailscale/tailscaled.state"
-	case "aix":
-		return "/var/tailscale/tailscaled.state"
-	default:
-		return ""
-	}
+	return "@VARBASE@/db/tailscale/tailscaled.state"
 }
 
 func stateFileUnix() string {
