$NetBSD: patch-src_tools_cargo_tests_testsuite_build.rs,v 1.6 2021/04/19 17:08:09 he Exp $

Don't attempt incremental operations on sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/tests/testsuite/build.rs.orig	2021-02-10 17:37:00.000000000 +0000
+++ src/tools/cargo/tests/testsuite/build.rs
@@ -45,6 +45,7 @@ fn cargo_fail_with_no_stderr() {
 
 /// Checks that the `CARGO_INCREMENTAL` environment variable results in
 /// `rustc` getting `-C incremental` passed to it.
+#[cfg(not(target_arch = "sparc64"))]
 #[cargo_test]
 fn cargo_compile_incremental() {
     let p = project()
@@ -67,6 +68,7 @@ fn cargo_compile_incremental() {
         .run();
 }
 
+#[cfg(not(target_arch = "sparc64"))]
 #[cargo_test]
 fn incremental_profile() {
     let p = project()
@@ -109,6 +111,7 @@ fn incremental_profile() {
         .run();
 }
 
+#[cfg(not(target_arch = "sparc64"))]
 #[cargo_test]
 fn incremental_config() {
     let p = project()
