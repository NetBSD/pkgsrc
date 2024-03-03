$NetBSD: patch-compiler_rustc__llvm_build.rs,v 1.16 2024/03/03 14:53:32 he Exp $

Fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

Pick up -latomic tweak from
https://github.com/rust-lang/rust/issues/104220
and
https://github.com/rust-lang/rust/pull/104572

--- compiler/rustc_llvm/build.rs.orig	2023-10-03 02:52:17.000000000 +0000
+++ compiler/rustc_llvm/build.rs
@@ -249,6 +249,10 @@ fn main() {
     {
         // 32-bit targets need to link libatomic.
         println!("cargo:rustc-link-lib=atomic");
+        if target.contains("netbsd")
+        {
+            println!("cargo:rustc-link-lib=z");
+        }
     } else if target.contains("windows-gnu") {
         println!("cargo:rustc-link-lib=shell32");
         println!("cargo:rustc-link-lib=uuid");
@@ -261,7 +265,11 @@ fn main() {
         // On NetBSD/i386, gcc and g++ is built for i486 (to maximize backward compat)
         // However, LLVM insists on using 64-bit atomics.
         // This gives rise to a need to link rust itself with -latomic for these targets
-        if target.starts_with("i586") || target.starts_with("i686") {
+        if target.starts_with("i386") 
+           || target.starts_with("i486") 
+           || target.starts_with("i586") 
+           || target.starts_with("i686")
+        {
             println!("cargo:rustc-link-lib=atomic");
         }
         println!("cargo:rustc-link-lib=z");
@@ -352,7 +360,13 @@ fn main() {
         "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
         // NetBSD uses a separate library when relocation is required
-        "stdc++_p"
+	if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+            "c++_pic"
+	} else {
+            "stdc++_pic"
+	}
+    } else if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+	"c++"
     } else if llvm_use_libcxx.is_some() {
         "c++"
     } else {
