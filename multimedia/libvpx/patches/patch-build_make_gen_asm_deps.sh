$NetBSD: patch-build_make_gen_asm_deps.sh,v 1.3 2015/11/18 14:09:25 ryoon Exp $

Fix build problems under Mac OS X with Xcode 4.4 and newer. Patch
taken from here:

https://github.com/mxcl/homebrew/issues/12567#issuecomment-6434000

--- build/make/gen_asm_deps.sh.orig	2015-11-09 22:12:38.000000000 +0000
+++ build/make/gen_asm_deps.sh
@@ -1,4 +1,4 @@
-#!/bin/sh
+#!/usr/pkg/bin/bash
 ##
 ##  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 ##
@@ -42,7 +42,7 @@ done
 
 [ -n "$srcfile" ] || show_help
 sfx=${sfx:-asm}
-includes=$(LC_ALL=C egrep -i "include +\"?[a-z0-9_/]+\.${sfx}" $srcfile |
+includes=$(LC_ALL=C egrep -i "include +\"[a-z0-9_/]+\.${sfx}" $srcfile |
            perl -p -e "s;.*?([a-z0-9_/]+.${sfx}).*;\1;")
 #" restore editor state
 for inc in ${includes}; do
