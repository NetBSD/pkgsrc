$NetBSD: patch-.._vendor_wide-0.7.33_src_f64x2__.rs,v 1.1 2025/12/08 12:40:16 adam Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.33/src/f64x2_.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/wide-0.7.33/src/f64x2_.rs
@@ -23,7 +23,7 @@ pick! {
         u64x2_all_true(f64x2_eq(self.simd, other.simd))
       }
     }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -100,7 +100,7 @@ impl Add for f64x2 {
         Self { sse: add_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vaddq_f64(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -122,7 +122,7 @@ impl Sub for f64x2 {
         Self { sse: sub_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vsubq_f64(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -144,7 +144,7 @@ impl Mul for f64x2 {
         Self { sse: mul_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_mul(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmulq_f64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -166,7 +166,7 @@ impl Div for f64x2 {
         Self { sse: div_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_div(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vdivq_f64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -260,7 +260,7 @@ impl BitAnd for f64x2 {
         Self { sse: bitand_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vandq_u64(vreinterpretq_u64_f64(self.neon), vreinterpretq_u64_f64(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -282,7 +282,7 @@ impl BitOr for f64x2 {
         Self { sse: bitor_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vorrq_u64(vreinterpretq_u64_f64(self.neon), vreinterpretq_u64_f64(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -304,7 +304,7 @@ impl BitXor for f64x2 {
         Self { sse: bitxor_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(veorq_u64(vreinterpretq_u64_f64(self.neon), vreinterpretq_u64_f64(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -326,7 +326,7 @@ impl CmpEq for f64x2 {
         Self { sse: cmp_eq_mask_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vceqq_f64(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -348,7 +348,7 @@ impl CmpGe for f64x2 {
         Self { sse: cmp_ge_mask_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_ge(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vcgeq_f64(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -372,7 +372,7 @@ impl CmpGt for f64x2 {
         Self { sse: cmp_gt_mask_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vcgtq_f64(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -394,7 +394,7 @@ impl CmpNe for f64x2 {
         Self { sse: cmp_neq_mask_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_ne(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vceqq_f64(self.neon, rhs.neon)) }.not() }
       } else {
         Self { arr: [
@@ -416,7 +416,7 @@ impl CmpLe for f64x2 {
         Self { sse: cmp_le_mask_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_le(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vcleq_f64(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -438,7 +438,7 @@ impl CmpLt for f64x2 {
         Self { sse: cmp_lt_mask_m128d(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vcltq_f64(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -475,7 +475,7 @@ impl f64x2 {
     pick! {
       if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vabsq_f64(self.neon) }}
       } else {
         let non_sign_bits = f64x2::from(f64::from_bits(i64::MAX as u64));
@@ -491,7 +491,7 @@ impl f64x2 {
         Self { simd: f64x2_floor(self.simd) }
       } else if #[cfg(target_feature="sse4.1")] {
         Self { sse: floor_m128d(self.sse) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vrndmq_f64(self.neon) }}
       } else if #[cfg(feature="std")] {
         let base: [f64; 2] = cast(self);
@@ -514,7 +514,7 @@ impl f64x2 {
         Self { simd: f64x2_ceil(self.simd) }
       } else if #[cfg(target_feature="sse4.1")] {
         Self { sse: ceil_m128d(self.sse) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vrndpq_f64(self.neon) }}
       } else if #[cfg(feature="std")] {
         let base: [f64; 2] = cast(self);
@@ -543,7 +543,7 @@ impl f64x2 {
         Self {
           simd: f64x2_pmax(self.simd, rhs.simd),
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmaxq_f64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -580,7 +580,7 @@ impl f64x2 {
             f64x2_ne(self.simd, self.simd), // NaN check
           )
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmaxnmq_f64(self.neon, rhs.neon) }}
             } else {
         Self { arr: [
@@ -604,7 +604,7 @@ impl f64x2 {
         Self {
           simd: f64x2_pmin(self.simd, rhs.simd),
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminq_f64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -641,7 +641,7 @@ impl f64x2 {
             f64x2_ne(self.simd, self.simd), // NaN check
           )
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminnmq_f64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -660,7 +660,7 @@ impl f64x2 {
         Self { sse: cmp_unord_mask_m128d(self.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_ne(self.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u64(vceqq_f64(self.neon, self.neon)) }.not() }
       } else {
         Self { arr: [
@@ -1269,7 +1269,7 @@ impl f64x2 {
         Self { sse: sqrt_m128d(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_sqrt(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vsqrtq_f64(self.neon) }}
       } else if #[cfg(feature="std")] {
         Self { arr: [
@@ -1292,7 +1292,7 @@ impl f64x2 {
         move_mask_m128d(self.sse)
       } else if #[cfg(target_feature="simd128")] {
         u64x2_bitmask(self.simd) as i32
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe
         {
           let e = vreinterpretq_u64_f64(self.neon);
@@ -1436,7 +1436,7 @@ impl f64x2 {
       } else if #[cfg(any(target_feature="sse2", target_feature="simd128"))] {
         let a: [f64;2] = cast(self);
         a.iter().sum()
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { vgetq_lane_f64(self.neon,0) + vgetq_lane_f64(self.neon,1) }
       } else {
         self.arr.iter().sum()
@@ -1652,7 +1652,7 @@ impl f64x2 {
         Self { sse: convert_to_m128d_from_lower2_i32_m128i(v.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f64x2_convert_low_i32x4(v.simd)}
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
         Self { neon: unsafe { vcvtq_f64_s64(vmovl_s32(vget_low_s32(v.neon))) }}
       } else {
         Self { arr: [
@@ -1682,7 +1682,7 @@ impl Not for f64x2 {
         Self { sse: self.sse.not() }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_not(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f64_u32(vmvnq_u32(vreinterpretq_u32_f64(self.neon))) }}
       } else {
         Self { arr: [
