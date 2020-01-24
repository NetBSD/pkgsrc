$NetBSD: patch-configure.py,v 1.3 2020/01/24 18:57:09 adam Exp $

Support Clang/LLVM 10+
https://github.com/nodejs/node/issues/29536

--- configure.py.orig	2020-01-09 20:45:57.000000000 +0000
+++ configure.py
@@ -705,7 +705,7 @@ def get_nasm_version(asm):
 
 def get_llvm_version(cc):
   return get_version_helper(
-    cc, r"(^(?:FreeBSD )?clang version|based on LLVM) ([3-9]\.[0-9]+)")
+    cc, r"(^(?:FreeBSD )?clang version|based on LLVM) ((\d{2}|[3-9])\.[0-9]+)")
 
 def get_xcode_version(cc):
   return get_version_helper(
