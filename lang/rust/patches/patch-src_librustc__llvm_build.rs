$NetBSD: patch-src_librustc__llvm_build.rs,v 1.1 2019/01/05 23:29:40 tnn Exp $

fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

--- src/librustc_llvm/build.rs.orig	2018-12-18 23:11:17.000000000 +0000
+++ src/librustc_llvm/build.rs
@@ -250,9 +250,17 @@ fn main() {
         "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
         // NetBSD uses a separate library when relocation is required
-        "stdc++_pic"
+        if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+            "c++_pic"
+        } else {
+            "stdc++_pic"
+        }
     } else {
-        "stdc++"
+        if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+            "c++"
+        } else {
+            "stdc++"
+        }
     };
 
     // C++ runtime library
