$NetBSD: patch-configure.py,v 1.2 2019/12/29 15:40:00 adam Exp $

Support Clang/LLVM 10+
https://github.com/nodejs/node/issues/29536

--- configure.py.orig	2019-08-15 19:20:03.000000000 +0000
+++ configure.py
@@ -705,11 +705,11 @@ def get_nasm_version(asm):
 
 def get_llvm_version(cc):
   return get_version_helper(
-    cc, r"(^(?:FreeBSD )?clang version|based on LLVM) ([3-9]\.[0-9]+)")
+    cc, r"(^(?:FreeBSD )?clang version|based on LLVM) ((\d{2}|[3-9])\.[0-9]+)")
 
 def get_xcode_version(cc):
   return get_version_helper(
-    cc, r"(^Apple LLVM version) ([0-9]+\.[0-9]+)")
+    cc, r"(^Apple (?:clang|LLVM) version) ([0-9]+\.[0-9]+)")
 
 def get_gas_version(cc):
   try:
