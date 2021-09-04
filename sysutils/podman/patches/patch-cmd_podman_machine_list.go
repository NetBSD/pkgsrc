$NetBSD: patch-cmd_podman_machine_list.go,v 1.1 2021/09/04 20:28:42 maya Exp $

https://github.com/containers/podman/pull/11434

--- cmd/podman/machine/list.go.orig	2021-08-30 19:15:26.000000000 +0000
+++ cmd/podman/machine/list.go
@@ -1,4 +1,4 @@
-// +build amd64,linux arm64,linux amd64,darwin arm64,darwin
+// +build amd64,!windows arm64,!windows
 
 package machine
 
