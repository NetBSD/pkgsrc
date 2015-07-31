$NetBSD: patch-src_net_cgo__stub.go,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/net/cgo_stub.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/net/cgo_stub.go
@@ -2,7 +2,7 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-// +build !cgo netgo
+// +build !cgo netgo solaris
 
 // Stub cgo routines for systems that do not use cgo to do network lookups.
 
