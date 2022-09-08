$NetBSD: patch-vendor_gvisor.dev_gvisor_pkg_sync_runtime__amd64.go,v 1.1 2022/09/08 18:15:46 bsiegert Exp $

Make this build under Go 1.19. Patch from upstream.
https://github.com/google/gvisor/commit/974792ae18cf19f555a35d3bf7b23a8ed9e9385c

--- vendor/gvisor.dev/gvisor/pkg/sync/runtime_amd64.go.orig	2022-07-20 07:20:35.000000000 +0000
+++ vendor/gvisor.dev/gvisor/pkg/sync/runtime_amd64.go
@@ -3,8 +3,8 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-//go:build amd64 && go1.8 && !go1.19 && !goexperiment.staticlockranking
-// +build amd64,go1.8,!go1.19,!goexperiment.staticlockranking
+//go:build amd64 && go1.8 && !go1.21 && !goexperiment.staticlockranking
+// +build amd64,go1.8,!go1.21,!goexperiment.staticlockranking
 
 package sync
 
