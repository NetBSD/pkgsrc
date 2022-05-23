$NetBSD: patch-ffbuild_libversion.sh,v 1.1 2022/05/23 00:35:02 dholland Exp $

Add missing shebang.

--- ffbuild/libversion.sh~	2021-10-21 17:06:35.000000000 +0000
+++ ffbuild/libversion.sh
@@ -1,3 +1,5 @@
+#!/bin/sh
+
 toupper(){
     echo "$@" | tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ
 }
