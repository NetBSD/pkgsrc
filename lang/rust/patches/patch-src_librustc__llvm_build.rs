$NetBSD: patch-src_librustc__llvm_build.rs,v 1.6 2019/09/19 17:37:29 jperkin Exp $

fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

--- src/librustc_llvm/build.rs.orig	2019-08-13 06:27:22.000000000 +0000
+++ src/librustc_llvm/build.rs
@@ -261,7 +261,13 @@ fn main() {
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
