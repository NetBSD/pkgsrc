$NetBSD: patch-src_runtime_cgo_gcc__setenv.c,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/runtime/cgo/gcc_setenv.c.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/runtime/cgo/gcc_setenv.c
@@ -2,7 +2,7 @@
 // Use of this source code is governed by a BSD-style
 // license that can be found in the LICENSE file.
 
-// +build darwin dragonfly freebsd linux netbsd openbsd
+// +build darwin dragonfly freebsd linux netbsd openbsd solaris
 
 #include "libcgo.h"
 
