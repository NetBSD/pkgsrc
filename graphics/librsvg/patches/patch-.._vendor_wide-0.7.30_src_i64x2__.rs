$NetBSD: patch-.._vendor_wide-0.7.30_src_i64x2__.rs,v 1.1 2025/09/23 11:12:16 adam Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.30/src/i64x2_.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/wide-0.7.30/src/i64x2_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for i64x2 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -72,7 +72,7 @@ impl Add for i64x2 {
         Self { sse: add_i64_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i64x2_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vaddq_s64(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -94,7 +94,7 @@ impl Sub for i64x2 {
         Self { sse: sub_i64_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i64x2_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vsubq_s64(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -191,7 +191,7 @@ impl BitAnd for i64x2 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vandq_s64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -213,7 +213,7 @@ impl BitOr for i64x2 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vorrq_s64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -235,7 +235,7 @@ impl BitXor for i64x2 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: veorq_s64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -261,7 +261,7 @@ macro_rules! impl_shl_t_for_i64x2 {
             Self { sse: shl_all_u64_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: i64x2_shl(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
             unsafe {Self { neon: vshlq_s64(self.neon, vmovq_n_s64(rhs as i64)) }}
           } else {
             let u = rhs as u64;
@@ -314,7 +314,7 @@ impl CmpEq for i64x2 {
         Self { sse: cmp_eq_mask_i64_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i64x2_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_s64_u64(vceqq_s64(self.neon, rhs.neon)) }}
       } else {
         let s: [i64;2] = cast(self);
@@ -338,7 +338,7 @@ impl CmpGt for i64x2 {
         Self { sse: cmp_gt_mask_i64_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i64x2_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_s64_u64(vcgtq_s64(self.neon, rhs.neon)) }}
       } else {
         let s: [i64;2] = cast(self);
@@ -362,7 +362,7 @@ impl CmpLt for i64x2 {
         Self { sse: !cmp_gt_mask_i64_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i64x2_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_s64_u64(vcltq_s64(self.neon, rhs.neon)) }}
       } else {
         let s: [i64;2] = cast(self);
@@ -390,7 +390,7 @@ impl i64x2 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vbslq_s64(vreinterpretq_u64_s64(self.neon), t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -405,7 +405,7 @@ impl i64x2 {
       // x86 doesn't have this builtin
       if #[cfg(target_feature="simd128")] {
         Self { simd: i64x2_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vabsq_s64(self.neon) }}
       } else {
         let arr: [i64; 2] = cast(self);
@@ -425,7 +425,7 @@ impl i64x2 {
       // x86 doesn't have this builtin
       if #[cfg(target_feature="simd128")] {
         u64x2 { simd: i64x2_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {u64x2 { neon: vreinterpretq_u64_s64(vabsq_s64(self.neon)) }}
       } else {
         let arr: [i64; 2] = cast(self);
