$NetBSD: patch-src_pkg_os_signal_signal__test.go,v 1.1 2013/07/07 08:10:14 wiz Exp $

This test fails when Go is built in pkgsrc, but it succeeds on the command
line (at least on NetBSD/amd64).
--- src/pkg/os/signal/signal_test.go.orig	2013-05-02 12:07:05.000000000 +0000
+++ src/pkg/os/signal/signal_test.go
@@ -2,7 +2,7 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-// +build darwin freebsd linux netbsd openbsd
+// +build ignore
 
 package signal
 
