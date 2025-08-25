$NetBSD: patch-src_tools_cargo_tests_testsuite_build.rs,v 1.18 2025/08/25 17:51:12 wiz Exp $

Don't attempt incremental operations on sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/tests/testsuite/build.rs.orig	2025-01-27 23:20:59.000000000 +0000
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
 #[cargo_test]
 fn incremental_profile() {
     let p = project()
@@ -175,6 +178,7 @@ fn incremental_profile() {
         .run();
 }
 
+#[cfg(not(target_arch = "sparc64"))]
 #[cargo_test]
 fn incremental_config() {
     let p = project()
