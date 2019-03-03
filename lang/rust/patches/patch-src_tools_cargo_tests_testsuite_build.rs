$NetBSD: patch-src_tools_cargo_tests_testsuite_build.rs,v 1.3 2019/03/03 09:16:21 he Exp $

Don't attempt incremental operations on sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/tests/testsuite/build.rs.orig	2018-10-24 20:01:28.000000000 +0000
+++ src/tools/cargo/tests/testsuite/build.rs
@@ -38,6 +38,7 @@ fn cargo_fail_with_no_stderr() {
 
 /// Check that the `CARGO_INCREMENTAL` environment variable results in
 /// `rustc` getting `-Zincremental` passed to it.
+#[cfg(not(target_arch = "sparc64"))]
 #[test]
 fn cargo_compile_incremental() {
     let p = project()
@@ -60,6 +61,7 @@ fn cargo_compile_incremental() {
         .run();
 }
 
+#[cfg(not(target_arch = "sparc64"))]
 #[test]
 fn incremental_profile() {
     let p = project()
@@ -102,6 +104,7 @@ fn incremental_profile() {
         .run();
 }
 
+#[cfg(not(target_arch = "sparc64"))]
 #[test]
 fn incremental_config() {
     let p = project()
