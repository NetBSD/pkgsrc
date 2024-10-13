$NetBSD: patch-tools_rust-analyzer_lib_line-index-src_lib.rs,v 1.1 2024/10/13 19:04:39 he Exp $

Try to avoid using neon for big-endian aarch64.
Ref. https://github.com/rust-lang/rust/issues/129819

--- src/tools/rust-analyzer/lib/line-index/src/lib.rs.orig	2024-09-01 14:12:57.016998002 +0000
+++ src/tools/rust-analyzer/lib/line-index/src/lib.rs
@@ -227,7 +227,7 @@ fn analyze_source_file_dispatch(
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 fn analyze_source_file_dispatch(
     src: &str,
     lines: &mut Vec<TextSize>,
@@ -339,7 +339,7 @@ unsafe fn analyze_source_file_sse2(
 }
 
 #[target_feature(enable = "neon")]
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 #[inline]
 // See https://community.arm.com/arm-community-blogs/b/infrastructure-solutions-blog/posts/porting-x86-vector-bitmask-optimizations-to-arm-neon
 //
@@ -354,7 +354,7 @@ unsafe fn move_mask(v: std::arch::aarch6
 }
 
 #[target_feature(enable = "neon")]
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 unsafe fn analyze_source_file_neon(
     src: &str,
     lines: &mut Vec<TextSize>,
@@ -433,7 +433,11 @@ unsafe fn analyze_source_file_neon(
     }
 }
 
-#[cfg(not(any(target_arch = "x86", target_arch = "x86_64", target_arch = "aarch64")))]
+#[cfg(not(any(
+    target_arch = "x86",
+    target_arch = "x86_64",
+    all(target_arch = "aarch64", target_endian = "little")
+)))]
 // The target (or compiler version) does not support SSE2 ...
 fn analyze_source_file_dispatch(
     src: &str,
