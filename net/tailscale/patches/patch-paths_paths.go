$NetBSD: patch-paths_paths.go,v 1.2 2026/10/08 16:08:15 ktnb Exp $

Follow hier(7).

--- paths/paths.go.orig	2026-10-08 00:18:58.000000000 +0000
+++ paths/paths.go
@@ -56,36 +56,7 @@ func DefaultTailscaledSocket() string {
 	if runtime.GOOS == "windows" {
 		return WindowsProtectedPipePrefix + `Tailscale\tailscaled`
 	}
-	if runtime.GOOS == "darwin" {
-		return "/var/run/tailscaled.socket"
-	}
-	if runtime.GOOS == "plan9" {
-		return "/srv/tailscaled.sock"
-	}
-	if runtime.GOOS == "android" {
-		// Android (e.g. a userspace tailscaled under Termux) has no /var,
-		// and the cwd-relative fallback below only works when the daemon
-		// and the CLI happen to be started from the same directory
-		// (see #21161). Use the shared per-app temp directory so both
-		// agree on an absolute path.
-		return filepath.Join(os.TempDir(), "tailscaled.sock")
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
