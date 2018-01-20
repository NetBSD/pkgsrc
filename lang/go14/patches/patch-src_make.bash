$NetBSD: patch-src_make.bash,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Workaround for Warninig armv5 instruction in GCC4.8 generic arm compiler 

--- src/make.bash.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/make.bash
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/usr/pkg/bin/bash
 # Copyright 2009 The Go Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style
 # license that can be found in the LICENSE file.
@@ -121,6 +121,15 @@ case "$GOHOSTARCH" in
 386) mflag=-m32;;
 amd64) mflag=-m64;;
 esac
+
+# In gcc 4.8 on NetBSD 7.0, need -march=armv5 flag for arm target.
+# Default target of gcc is generic-arm. however some assemble-sources
+# in golang use operator for armv5 or lator.
+
+if [ "$GOARCH" == "arm" -o -z '$GOARCH' -a "$(uname -sp)" == "NetBSD earm" ]; then
+		mflag="-march=armv5"
+fi
+
 if [ "$(uname)" == "Darwin" ]; then
 	# golang.org/issue/5261
 	mflag="$mflag -mmacosx-version-min=10.6"
