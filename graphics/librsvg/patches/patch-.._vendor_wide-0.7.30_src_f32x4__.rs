$NetBSD: patch-.._vendor_wide-0.7.30_src_f32x4__.rs,v 1.1 2025/09/23 11:12:16 adam Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.30/src/f32x4_.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/wide-0.7.30/src/f32x4_.rs
@@ -23,7 +23,7 @@ pick! {
         u32x4_all_true(f32x4_eq(self.simd, other.simd))
       }
     }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -98,7 +98,7 @@ impl Add for f32x4 {
         Self { sse: add_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vaddq_f32(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -122,7 +122,7 @@ impl Sub for f32x4 {
         Self { sse: sub_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vsubq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -146,7 +146,7 @@ impl Mul for f32x4 {
         Self { sse: mul_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_mul(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmulq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -170,7 +170,7 @@ impl Div for f32x4 {
         Self { sse: div_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_div(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vdivq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -266,7 +266,7 @@ impl BitAnd for f32x4 {
         Self { sse: bitand_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vandq_u32(vreinterpretq_u32_f32(self.neon), vreinterpretq_u32_f32(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -290,7 +290,7 @@ impl BitOr for f32x4 {
         Self { sse: bitor_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vorrq_u32(vreinterpretq_u32_f32(self.neon), vreinterpretq_u32_f32(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -314,7 +314,7 @@ impl BitXor for f32x4 {
         Self { sse: bitxor_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(veorq_u32(vreinterpretq_u32_f32(self.neon), vreinterpretq_u32_f32(rhs.neon))) }}
       } else {
         Self { arr: [
@@ -338,7 +338,7 @@ impl CmpEq for f32x4 {
         Self { sse: cmp_eq_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vceqq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -362,7 +362,7 @@ impl CmpGe for f32x4 {
         Self { sse: cmp_ge_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_ge(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vcgeq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -386,7 +386,7 @@ impl CmpGt for f32x4 {
         Self { sse: cmp_gt_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vcgtq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -410,7 +410,7 @@ impl CmpNe for f32x4 {
         Self { sse: cmp_neq_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_ne(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vmvnq_u32(vceqq_f32(self.neon, rhs.neon))) }}
       } else {
         Self { arr: [
@@ -434,7 +434,7 @@ impl CmpLe for f32x4 {
         Self { sse: cmp_le_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_le(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vcleq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -458,7 +458,7 @@ impl CmpLt for f32x4 {
         Self { sse: cmp_lt_mask_m128(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vcltq_f32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -498,7 +498,7 @@ impl f32x4 {
     pick! {
       if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vabsq_f32(self.neon) }}
       } else {
         let non_sign_bits = f32x4::from(f32::from_bits(i32::MAX as u32));
@@ -520,7 +520,7 @@ impl f32x4 {
         Self {
           simd: f32x4_pmax(self.simd, rhs.simd),
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmaxq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -559,7 +559,7 @@ impl f32x4 {
             f32x4_ne(self.simd, self.simd), // NaN check
           )
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmaxnmq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -585,7 +585,7 @@ impl f32x4 {
         Self {
           simd: f32x4_pmin(self.simd, rhs.simd),
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -624,7 +624,7 @@ impl f32x4 {
             f32x4_ne(self.simd, self.simd), // NaN check
           )
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminnmq_f32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -644,7 +644,7 @@ impl f32x4 {
         Self { sse: cmp_unord_mask_m128(self.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_ne(self.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_f32_u32(vmvnq_u32(vceqq_f32(self.neon, self.neon))) }}
       } else {
         Self { arr: [
@@ -689,7 +689,7 @@ impl f32x4 {
         mask.blend(self, f)
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_nearest(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vrndnq_f32(self.neon) }}
       } else {
         // Note(Lokathor): This software fallback is probably very slow compared
@@ -753,7 +753,7 @@ impl f32x4 {
         flip_to_max ^ cast
       } else if #[cfg(target_feature="simd128")] {
         cast(Self { simd: i32x4_trunc_sat_f32x4(f32x4_nearest(self.simd)) })
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         cast(unsafe {Self { neon: vreinterpretq_f32_s32(vcvtnq_s32_f32(self.neon)) }})
       } else {
         let rounded: [f32; 4] = cast(self.round());
@@ -798,7 +798,7 @@ impl f32x4 {
         flip_to_max ^ cast
       } else if #[cfg(target_feature="simd128")] {
         cast(Self { simd: i32x4_trunc_sat_f32x4(self.simd) })
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         cast(unsafe {Self { neon: vreinterpretq_f32_s32(vcvtq_s32_f32(self.neon)) }})
       } else {
         let n: [f32;4] = cast(self);
@@ -1165,7 +1165,7 @@ impl f32x4 {
         Self { sse: reciprocal_m128(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_div(f32x4_splat(1.0), self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vdivq_f32(vdupq_n_f32(1.0), self.neon) }}
       } else {
         Self { arr: [
@@ -1185,7 +1185,7 @@ impl f32x4 {
         Self { sse: reciprocal_sqrt_m128(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_div(f32x4_splat(1.0), f32x4_sqrt(self.simd)) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vdivq_f32(vdupq_n_f32(1.0), vsqrtq_f32(self.neon)) }}
       } else if #[cfg(feature="std")] {
         Self { arr: [
@@ -1212,7 +1212,7 @@ impl f32x4 {
         Self { sse: sqrt_m128(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_sqrt(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vsqrtq_f32(self.neon) }}
       } else if #[cfg(feature="std")] {
         Self { arr: [
@@ -1240,7 +1240,7 @@ impl f32x4 {
         move_mask_m128(self.sse)
       } else if #[cfg(target_feature="simd128")] {
         u32x4_bitmask(self.simd) as i32
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe
         {
           // set all to 1 if top bit is set, else 0
@@ -1575,7 +1575,7 @@ impl f32x4 {
         Self { sse: convert_to_m128_from_i32_m128i(v.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: f32x4_convert_i32x4(v.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
         Self { neon: unsafe { vcvtq_f32_s32(v.neon) }}
       } else {
         Self { arr: [
