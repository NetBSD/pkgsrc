$NetBSD: patch-cmd_podman_registry_config.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Add netbsd support

--- cmd/podman/registry/config.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ cmd/podman/registry/config.go
@@ -59,7 +59,7 @@ func newPodmanConfig() {
 
 	var mode entities.EngineMode
 	switch runtime.GOOS {
-	case "darwin", "windows":
+	case "darwin", "netbsd", "windows":
 		mode = entities.TunnelMode
 	case "linux", "freebsd":
 		// Some linux clients might only be compiled without ABI
