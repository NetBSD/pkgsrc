$NetBSD: patch-src_tools_cargo_tests_testsuite_build.rs,v 1.15 2024/11/24 16:13:43 he Exp $

Don't attempt incremental operations on sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/tests/testsuite/build.rs.orig	2019-08-13 06:27:40.000000000 +0000
+++ src/tools/cargo/tests/testsuite/build.rs
@@ -41,6 +41,7 @@ i am foo
         .run();
 }
 
+#[cfg(not(target_arch = "sparc64"))]
 #[cargo_test]
 fn build_with_symlink_to_path_dependency_with_build_script_in_git() {
     if !symlink_supported() {
@@ -103,6 +104,7 @@ fn cargo_fail_with_no_stderr() {
 
 /// Checks that the `CARGO_INCREMENTAL` environment variable results in
 /// `rustc` getting `-C incremental` passed to it.
+#[cfg(not(target_arch = "sparc64"))]
 #[cargo_test]
 fn cargo_compile_incremental() {
     let p = project()
@@ -132,6 +134,7 @@ fn cargo_compile_incremental() {
         .run();
 }
 
+#[cfg(not(target_arch = "sparc64"))]
 #[allow(deprecated)]
 #[cargo_test]
 fn incremental_profile() {
@@ -176,6 +179,7 @@ fn incremental_profile() {
         .run();
 }
 
+#[cfg(not(target_arch = "sparc64"))]
 #[allow(deprecated)]
 #[cargo_test]
 fn incremental_config() {
