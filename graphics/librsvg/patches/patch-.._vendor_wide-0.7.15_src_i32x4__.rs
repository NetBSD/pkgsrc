$NetBSD: patch-.._vendor_wide-0.7.15_src_i32x4__.rs,v 1.1 2025/02/15 23:41:46 he Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.15/src/i32x4_.rs.orig	2024-10-02 14:08:01.778610646 +0000
+++ ../vendor/wide-0.7.15/src/i32x4_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for i32x4 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -70,7 +70,7 @@ impl Add for i32x4 {
         Self { sse: add_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vaddq_s32(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -94,7 +94,7 @@ impl Sub for i32x4 {
         Self { sse: sub_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vsubq_s32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -118,7 +118,7 @@ impl Mul for i32x4 {
         Self { sse: mul_32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_mul(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vmulq_s32(self.neon, rhs.neon) }}
       } else {
         let arr1: [i32; 4] = cast(self);
@@ -198,7 +198,7 @@ impl BitAnd for i32x4 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vandq_s32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -222,7 +222,7 @@ impl BitOr for i32x4 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vorrq_s32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -246,7 +246,7 @@ impl BitXor for i32x4 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: veorq_s32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -274,7 +274,7 @@ macro_rules! impl_shl_t_for_i32x4 {
             Self { sse: shl_all_u32_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: i32x4_shl(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
             unsafe {Self { neon: vshlq_s32(self.neon, vmovq_n_s32(rhs as i32)) }}
           } else {
             let u = rhs as u64;
@@ -306,7 +306,7 @@ macro_rules! impl_shr_t_for_i32x4 {
             Self { sse: shr_all_i32_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: i32x4_shr(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
             unsafe {Self { neon: vshlq_s32(self.neon, vmovq_n_s32( -(rhs as i32))) }}
           } else {
             let u = rhs as u64;
@@ -334,7 +334,7 @@ impl CmpEq for i32x4 {
         Self { sse: cmp_eq_mask_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s32_u32(vceqq_s32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -358,7 +358,7 @@ impl CmpGt for i32x4 {
         Self { sse: cmp_gt_mask_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s32_u32(vcgtq_s32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -382,7 +382,7 @@ impl CmpLt for i32x4 {
         Self { sse: cmp_lt_mask_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s32_u32(vcltq_s32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -410,7 +410,7 @@ impl i32x4 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vbslq_s32(vreinterpretq_u32_s32(self.neon), t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -425,7 +425,7 @@ impl i32x4 {
         Self { sse: abs_i32_m128i(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vabsq_s32(self.neon) }}
       } else {
         let arr: [i32; 4] = cast(self);
@@ -460,7 +460,7 @@ impl i32x4 {
         Self { sse: min_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_min(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vminq_s32(self.neon, rhs.neon) }}
       } else {
         self.cmp_lt(rhs).blend(self, rhs)
@@ -475,7 +475,7 @@ impl i32x4 {
         cast(convert_to_m128_from_i32_m128i(self.sse))
       } else if #[cfg(target_feature="simd128")] {
         cast(Self { simd: f32x4_convert_i32x4(self.simd) })
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         cast(unsafe {Self { neon: vreinterpretq_s32_f32(vcvtq_f32_s32(self.neon)) }})
       } else {
         let arr: [i32; 4] = cast(self);
@@ -497,7 +497,7 @@ impl i32x4 {
         move_mask_m128(cast(self.sse))
       } else if #[cfg(target_feature="simd128")] {
         u32x4_bitmask(self.simd) as i32
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe
         {
           // set all to 1 if top bit is set, else 0
