$NetBSD: patch-compiler_rustc__llvm_build.rs,v 1.10 2023/01/23 18:49:04 he Exp $

Fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

Pick up -latomic tweak from
https://github.com/rust-lang/rust/issues/104220
and
https://github.com/rust-lang/rust/pull/104572

--- compiler/rustc_llvm/build.rs.orig	2021-11-01 07:17:29.000000000 +0000
+++ compiler/rustc_llvm/build.rs
@@ -235,20 +235,32 @@ fn main() {
     let mut cmd = Command::new(&llvm_config);
     cmd.arg(llvm_link_arg).arg("--libs");
 
-    if !is_crossed {
-        cmd.arg("--system-libs");
-    } else if target.contains("windows-gnu") {
-        println!("cargo:rustc-link-lib=shell32");
-        println!("cargo:rustc-link-lib=uuid");
-    } else if target.contains("netbsd") || target.contains("haiku") || target.contains("darwin") {
-        println!("cargo:rustc-link-lib=z");
-    } else if target.starts_with("arm")
+    if target.starts_with("arm")
         || target.starts_with("mips-")
         || target.starts_with("mipsel-")
         || target.starts_with("powerpc-")
     {
         // 32-bit targets need to link libatomic.
         println!("cargo:rustc-link-lib=atomic");
+        println!("cargo:rustc-link-lib=z");
+    } else if !is_crossed {
+        cmd.arg("--system-libs");
+    } else if target.contains("windows-gnu") {
+        println!("cargo:rustc-link-lib=shell32");
+        println!("cargo:rustc-link-lib=uuid");
+    } else if target.contains("netbsd")
+        || target.contains("haiku") 
+        || target.contains("darwin")
+    {
+	// We build for i486, and then need -latomic for 64-bit atomics
+        if target.starts_with("i386")
+            || target.starts_with("i486") 
+            || target.starts_with("i586") 
+            || target.starts_with("i686") 
+        {
+	    println!("cargo:rustc-link-lib=atomic");
+        }
+        println!("cargo:rustc-link-lib=z");
     }
     cmd.args(&components);
 
@@ -334,7 +346,13 @@ fn main() {
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
