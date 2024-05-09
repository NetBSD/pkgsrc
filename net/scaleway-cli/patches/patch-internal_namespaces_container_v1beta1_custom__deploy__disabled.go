$NetBSD: patch-internal_namespaces_container_v1beta1_custom__deploy__disabled.go,v 1.1 2024/05/09 20:46:28 leot Exp $

Needs github.com/buildpacks/lifecycle/internal/path that is only for
darwin, linux and windows.

Shared upstream via <https://github.com/scaleway/scaleway-cli/pull/3806>.

--- internal/namespaces/container/v1beta1/custom_deploy_disabled.go.orig	2024-05-09 20:01:32.287395065 +0000
+++ internal/namespaces/container/v1beta1/custom_deploy_disabled.go
@@ -1,4 +1,4 @@
-//go:build wasm || freebsd
+//go:build !(darwin || linux || windows)
 
 package container
 
