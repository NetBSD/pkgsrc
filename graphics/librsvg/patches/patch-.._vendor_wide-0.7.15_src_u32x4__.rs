$NetBSD: patch-.._vendor_wide-0.7.15_src_u32x4__.rs,v 1.1 2025/02/15 23:41:46 he Exp $

Do not try to use neon / SIMD on big-endian aarch64.

--- ../vendor/wide-0.7.15/src/u32x4_.rs.orig	2024-10-02 14:14:03.899924604 +0000
+++ ../vendor/wide-0.7.15/src/u32x4_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for u32x4 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -70,7 +70,7 @@ impl Add for u32x4 {
         Self { sse: add_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u32x4_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vaddq_u32(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -94,7 +94,7 @@ impl Sub for u32x4 {
         Self { sse: sub_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u32x4_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vsubq_u32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -118,7 +118,7 @@ impl Mul for u32x4 {
         Self { sse: mul_32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u32x4_mul(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vmulq_u32(self.neon, rhs.neon) }}
       } else {
         let arr1: [u32; 4] = cast(self);
@@ -198,7 +198,7 @@ impl BitAnd for u32x4 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vandq_u32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -222,7 +222,7 @@ impl BitOr for u32x4 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vorrq_u32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -246,7 +246,7 @@ impl BitXor for u32x4 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: veorq_u32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -274,7 +274,7 @@ macro_rules! impl_shl_t_for_u32x4 {
             Self { sse: shl_all_u32_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: u32x4_shl(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
             unsafe {Self { neon: vshlq_u32(self.neon, vmovq_n_s32(rhs as i32)) }}
           } else {
             let u = rhs as u64;
@@ -306,7 +306,7 @@ macro_rules! impl_shr_t_for_u32x4 {
             Self { sse: shr_all_u32_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: u32x4_shr(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
             unsafe {Self { neon: vshlq_u32(self.neon, vmovq_n_s32( -(rhs as i32))) }}
           } else {
             let u = rhs as u64;
@@ -338,7 +338,7 @@ impl u32x4 {
         Self { sse: cmp_eq_mask_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u32x4_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vceqq_u32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -358,7 +358,7 @@ impl u32x4 {
         Self { sse: cmp_gt_mask_i32_m128i(self.sse,rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u32x4_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vcgtq_u32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -378,7 +378,7 @@ impl u32x4 {
         Self { sse: cmp_lt_mask_i32_m128i(self.sse,rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u32x4_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vcltq_u32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -398,7 +398,7 @@ impl u32x4 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vbslq_u32(self.neon, t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -413,9 +413,9 @@ impl u32x4 {
         Self { sse: max_u32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u32x4_max(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vmaxq_u32(self.neon, rhs.neon) }}
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vmaxq_u16(self.neon, rhs.neon) }}
       } else {
         let arr: [u32; 4] = cast(self);
@@ -437,7 +437,7 @@ impl u32x4 {
         Self { sse: min_u32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u32x4_min(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vminq_u32(self.neon, rhs.neon) }}
       } else {
         let arr: [u32; 4] = cast(self);
