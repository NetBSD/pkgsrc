$NetBSD: patch-runtime_check__user__unix.go,v 1.1 2022/07/23 18:50:10 leot Exp $

Treat most Unix-es like macos by just checking uid and gid.

--- runtime/check_user_unix.go.orig	2022-07-13 08:24:48.000000000 +0000
+++ runtime/check_user_unix.go
@@ -1,3 +1,5 @@
+// +build !linux,!windows
+
 // Copyright 2022 The OPA Authors.  All rights reserved.
 // Use of this source code is governed by an Apache2
 // license that can be found in the LICENSE file.
