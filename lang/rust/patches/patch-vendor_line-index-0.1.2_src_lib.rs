$NetBSD: patch-vendor_line-index-0.1.2_src_lib.rs,v 1.2 2025/08/25 17:51:13 wiz Exp $

Do not attempt use of neon extension in big-endian mode.

--- vendor/line-index-0.1.2/src/lib.rs.orig	2025-02-03 07:59:39.771200202 +0000
+++ vendor/line-index-0.1.2/src/lib.rs
@@ -235,7 +235,7 @@ fn analyze_source_file_dispatch(
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 fn analyze_source_file_dispatch(
     src: &str,
     lines: &mut Vec<TextSize>,
@@ -347,7 +347,7 @@ unsafe fn analyze_source_file_sse2(
 }
 
 #[target_feature(enable = "neon")]
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 #[inline]
 // See https://community.arm.com/arm-community-blogs/b/infrastructure-solutions-blog/posts/porting-x86-vector-bitmask-optimizations-to-arm-neon
 //
@@ -362,7 +362,7 @@ unsafe fn move_mask(v: std::arch::aarch6
 }
 
 #[target_feature(enable = "neon")]
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 unsafe fn analyze_source_file_neon(
     src: &str,
     lines: &mut Vec<TextSize>,
@@ -441,7 +441,7 @@ unsafe fn analyze_source_file_neon(
     }
 }
 
-#[cfg(not(any(target_arch = "x86", target_arch = "x86_64", target_arch = "aarch64")))]
+#[cfg(not(any(target_arch = "x86", target_arch = "x86_64", all(target_arch = "aarch64", target_endian = "little"))))]
 // The target (or compiler version) does not support SSE2 ...
 fn analyze_source_file_dispatch(
     src: &str,
