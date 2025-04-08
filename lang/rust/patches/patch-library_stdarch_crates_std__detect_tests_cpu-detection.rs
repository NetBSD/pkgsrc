$NetBSD: patch-library_stdarch_crates_std__detect_tests_cpu-detection.rs,v 1.2 2025/04/08 09:31:06 wiz Exp $

On NetBSD/aarch64, do the same as FreeBSD and OpenBSD.

--- library/stdarch/crates/std_detect/tests/cpu-detection.rs.orig	2024-11-10 17:39:05.836052531 +0000
+++ library/stdarch/crates/std_detect/tests/cpu-detection.rs
@@ -166,7 +166,7 @@ fn aarch64_windows() {
 #[test]
 #[cfg(all(
     target_arch = "aarch64",
-    any(target_os = "freebsd", target_os = "openbsd")
+    any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd")
 ))]
 fn aarch64_bsd() {
     println!("asimd: {:?}", is_aarch64_feature_detected!("asimd"));
