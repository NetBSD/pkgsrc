$NetBSD: patch-.._vendor_wide-0.7.33_src_f32x4__.rs,v 1.1 2025/12/08 12:40:16 adam Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.33/src/f32x4_.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/wide-0.7.33/src/f32x4_.rs
@@ -23,7 +23,7 @@ pick! {
         u32x4_all_true(f32x4_eq(self.simd, other.simd))
       }
     }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -97,7 +97,7 @@ impl Add for f32x4 {
         Self { sse: add_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vaddq_f32(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -121,7 +121,7 @@ impl Sub for f32x4 {
         Self { sse: sub_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vsubq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -145,7 +145,7 @@ impl Mul for f32x4 {
         Self { sse: mul_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_mul(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmulq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -169,7 +169,7 @@ impl Div for f32x4 {
         Self { sse: div_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_div(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vdivq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -265,7 +265,7 @@ impl BitAnd for f32x4 {
         Self { sse: bitand_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vandq_u32(vreinterpretq_u32_f32(self.neon), vreinterpretq_u32_f32(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -289,7 +289,7 @@ impl BitOr for f32x4 {
         Self { sse: bitor_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vorrq_u32(vreinterpretq_u32_f32(self.neon), vreinterpretq_u32_f32(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -313,7 +313,7 @@ impl BitXor for f32x4 {
         Self { sse: bitxor_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(veorq_u32(vreinterpretq_u32_f32(self.neon), vreinterpretq_u32_f32(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -337,7 +337,7 @@ impl CmpEq for f32x4 {
         Self { sse: cmp_eq_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vceqq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -361,7 +361,7 @@ impl CmpGe for f32x4 {
         Self { sse: cmp_ge_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_ge(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vcgeq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -385,7 +385,7 @@ impl CmpGt for f32x4 {
         Self { sse: cmp_gt_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vcgtq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -409,7 +409,7 @@ impl CmpNe for f32x4 {
         Self { sse: cmp_neq_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_ne(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vmvnq_u32(vceqq_f32(self.neon, rhs.neon))) }}
       } else {
         Self { arr: [
@@ -433,7 +433,7 @@ impl CmpLe for f32x4 {
         Self { sse: cmp_le_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_le(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vcleq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -457,7 +457,7 @@ impl CmpLt for f32x4 {
         Self { sse: cmp_lt_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vcltq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -500,7 +500,7 @@ impl f32x4 {
     pick! {
       if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vabsq_f32(self.neon) }}
       } else {
         let non_sign_bits = f32x4::from(f32::from_bits(i32::MAX as u32));
@@ -516,7 +516,7 @@ impl f32x4 {
         Self { simd: f32x4_floor(self.simd) }
       } else if #[cfg(target_feature="sse4.1")] {
         Self { sse: floor_m128(self.sse) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vrndmq_f32(self.neon) }}
       } else if #[cfg(feature="std")] {
         let base: [f32; 4] = cast(self);
@@ -541,7 +541,7 @@ impl f32x4 {
         Self { simd: f32x4_ceil(self.simd) }
       } else if #[cfg(target_feature="sse4.1")] {
         Self { sse: ceil_m128(self.sse) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vrndpq_f32(self.neon) }}
       } else if #[cfg(feature="std")] {
         let base: [f32; 4] = cast(self);
@@ -572,7 +572,7 @@ impl f32x4 {
         Self {
           simd: f32x4_pmax(self.simd, rhs.simd),
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmaxq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -611,7 +611,7 @@ impl f32x4 {
             f32x4_ne(self.simd, self.simd), // NaN check
           )
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmaxnmq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -637,7 +637,7 @@ impl f32x4 {
         Self {
           simd: f32x4_pmin(self.simd, rhs.simd),
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -676,7 +676,7 @@ impl f32x4 {
             f32x4_ne(self.simd, self.simd), // NaN check
           )
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminnmq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -696,7 +696,7 @@ impl f32x4 {
         Self { sse: cmp_unord_mask_m128(self.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_ne(self.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vmvnq_u32(vceqq_f32(self.neon, self.neon))) }}
       } else {
         Self { arr: [
@@ -741,7 +741,7 @@ impl f32x4 {
         mask.blend(self, f)
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_nearest(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vrndnq_f32(self.neon) }}
       } else {
         // Note(Lokathor): This software fallback is probably very slow compared
@@ -805,7 +805,7 @@ impl f32x4 {
         flip_to_max ^ cast
       } else if #[cfg(target_feature="simd128")] {
         cast(Self { simd: i32x4_trunc_sat_f32x4(f32x4_nearest(self.simd)) })
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         cast(unsafe {Self { neon: vreinterpretq_f32_s32(vcvtnq_s32_f32(self.neon)) }})
       } else {
         let rounded: [f32; 4] = cast(self.round());
@@ -850,7 +850,7 @@ impl f32x4 {
         flip_to_max ^ cast
       } else if #[cfg(target_feature="simd128")] {
         cast(Self { simd: i32x4_trunc_sat_f32x4(self.simd) })
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         cast(unsafe {Self { neon: vreinterpretq_f32_s32(vcvtq_s32_f32(self.neon)) }})
       } else {
         let n: [f32;4] = cast(self);
@@ -1217,7 +1217,7 @@ impl f32x4 {
         Self { sse: reciprocal_m128(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_div(f32x4_splat(1.0), self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vdivq_f32(vdupq_n_f32(1.0), self.neon) }}
       } else {
         Self { arr: [
@@ -1237,7 +1237,7 @@ impl f32x4 {
         Self { sse: reciprocal_sqrt_m128(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_div(f32x4_splat(1.0), f32x4_sqrt(self.simd)) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vdivq_f32(vdupq_n_f32(1.0), vsqrtq_f32(self.neon)) }}
       } else if #[cfg(feature="std")] {
         Self { arr: [
@@ -1264,7 +1264,7 @@ impl f32x4 {
         Self { sse: sqrt_m128(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_sqrt(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vsqrtq_f32(self.neon) }}
       } else if #[cfg(feature="std")] {
         Self { arr: [
@@ -1292,7 +1292,7 @@ impl f32x4 {
         move_mask_m128(self.sse)
       } else if #[cfg(target_feature="simd128")] {
         u32x4_bitmask(self.simd) as i32
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe
         {
           // set all to 1 if top bit is set, else 0
@@ -1662,7 +1662,7 @@ impl f32x4 {
         Self { sse: convert_to_m128_from_i32_m128i(v.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_convert_i32x4(v.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
         Self { neon: unsafe { vcvtq_f32_s32(v.neon) }}
       } else {
         Self { arr: [
