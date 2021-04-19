$NetBSD: patch-compiler_rustc__llvm_build.rs,v 1.2 2021/04/19 17:08:09 he Exp $

Fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

--- compiler/rustc_llvm/build.rs.orig	2021-02-10 17:36:44.000000000 +0000
+++ compiler/rustc_llvm/build.rs
@@ -281,7 +281,13 @@ fn main() {
         "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
         // NetBSD uses a separate library when relocation is required
-        "stdc++_pic"
+        if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+            "c++_pic"
+        } else {
+            "stdc++_pic"
+        }
+    } else if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+        "c++"
     } else if llvm_use_libcxx.is_some() {
         "c++"
     } else {
