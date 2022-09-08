$NetBSD: patch-vendor_gvisor.dev_gvisor_pkg_sync_runtime__unsafe.go,v 1.1 2022/09/08 18:15:46 bsiegert Exp $

Make this build under Go 1.19. Patch from upstream.
https://github.com/google/gvisor/commit/974792ae18cf19f555a35d3bf7b23a8ed9e9385c

--- vendor/gvisor.dev/gvisor/pkg/sync/runtime_unsafe.go.orig	2022-07-20 07:20:35.000000000 +0000
+++ vendor/gvisor.dev/gvisor/pkg/sync/runtime_unsafe.go
@@ -3,8 +3,8 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-//go:build go1.13 && !go1.19
-// +build go1.13,!go1.19
+//go:build go1.13 && !go1.21
+// +build go1.13,!go1.21
 
 // //go:linkname directives type-checked by checklinkname. Any other
 // non-linkname assumptions outside the Go 1 compatibility guarantee should
