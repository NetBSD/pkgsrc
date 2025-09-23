$NetBSD: patch-.._vendor_wide-0.7.30_src_i32x4__.rs,v 1.1 2025/09/23 11:12:16 adam Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.30/src/i32x4_.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/wide-0.7.30/src/i32x4_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for i32x4 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -70,7 +70,7 @@ impl Add for i32x4 {
         Self { sse: add_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vaddq_s32(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -94,7 +94,7 @@ impl Sub for i32x4 {
         Self { sse: sub_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vsubq_s32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -118,7 +118,7 @@ impl Mul for i32x4 {
         Self { sse: mul_32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_mul(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmulq_s32(self.neon, rhs.neon) }}
       } else {
         let arr1: [i32; 4] = cast(self);
@@ -198,7 +198,7 @@ impl BitAnd for i32x4 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vandq_s32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -222,7 +222,7 @@ impl BitOr for i32x4 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vorrq_s32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -246,7 +246,7 @@ impl BitXor for i32x4 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: veorq_s32(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -274,7 +274,7 @@ macro_rules! impl_shl_t_for_i32x4 {
             Self { sse: shl_all_u32_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: i32x4_shl(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
             unsafe {Self { neon: vshlq_s32(self.neon, vmovq_n_s32(rhs as i32)) }}
           } else {
             let u = rhs as u64;
@@ -306,7 +306,7 @@ macro_rules! impl_shr_t_for_i32x4 {
             Self { sse: shr_all_i32_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: i32x4_shr(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
             unsafe {Self { neon: vshlq_s32(self.neon, vmovq_n_s32( -(rhs as i32))) }}
           } else {
             let u = rhs as u64;
@@ -340,7 +340,7 @@ impl Shr<i32x4> for i32x4 {
         // mask the shift count to 31 to have same behavior on all platforms
         let shift_by = bitand_m128i(rhs.sse, set_splat_i32_m128i(31));
         Self { sse: shr_each_i32_m128i(self.sse, shift_by) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {
           // mask the shift count to 31 to have same behavior on all platforms
           // no right shift, have to pass negative value to left shift on neon
@@ -377,7 +377,7 @@ impl Shl<i32x4> for i32x4 {
         // mask the shift count to 31 to have same behavior on all platforms
         let shift_by = bitand_m128i(rhs.sse, set_splat_i32_m128i(31));
         Self { sse: shl_each_u32_m128i(self.sse, shift_by) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {
           // mask the shift count to 31 to have same behavior on all platforms
           let shift_by = vandq_s32(rhs.neon, vmovq_n_s32(31));
@@ -407,7 +407,7 @@ impl CmpEq for i32x4 {
         Self { sse: cmp_eq_mask_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_s32_u32(vceqq_s32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -431,7 +431,7 @@ impl CmpGt for i32x4 {
         Self { sse: cmp_gt_mask_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_s32_u32(vcgtq_s32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -455,7 +455,7 @@ impl CmpLt for i32x4 {
         Self { sse: cmp_lt_mask_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vreinterpretq_s32_u32(vcltq_s32(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -483,7 +483,7 @@ impl i32x4 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vbslq_s32(vreinterpretq_u32_s32(self.neon), t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -520,7 +520,7 @@ impl i32x4 {
             a: i64x2 { simd: i64x2_extmul_low_i32x4(self.simd, rhs.simd) },
             b: i64x2 { simd: i64x2_extmul_high_i32x4(self.simd, rhs.simd) },
           }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
         unsafe {
           i64x4 { a: i64x2 { neon: vmull_s32(vget_low_s32(self.neon), vget_low_s32(rhs.neon)) },
                   b: i64x2 { neon: vmull_s32(vget_high_s32(self.neon), vget_high_s32(rhs.neon)) } }
@@ -546,7 +546,7 @@ impl i32x4 {
         Self { sse: abs_i32_m128i(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vabsq_s32(self.neon) }}
       } else {
         let arr: [i32; 4] = cast(self);
@@ -568,7 +568,7 @@ impl i32x4 {
         u32x4 { sse: abs_i32_m128i(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         u32x4 { simd: i32x4_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {u32x4 { neon: vreinterpretq_u32_s32(vabsq_s32(self.neon)) }}
       } else {
         let arr: [i32; 4] = cast(self);
@@ -638,7 +638,7 @@ impl i32x4 {
         Self { sse: min_i32_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i32x4_min(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminq_s32(self.neon, rhs.neon) }}
       } else {
         self.cmp_lt(rhs).blend(self, rhs)
@@ -653,7 +653,7 @@ impl i32x4 {
         cast(convert_to_m128_from_i32_m128i(self.sse))
       } else if #[cfg(target_feature="simd128")] {
         cast(Self { simd: f32x4_convert_i32x4(self.simd) })
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         cast(unsafe {Self { neon: vreinterpretq_s32_f32(vcvtq_f32_s32(self.neon)) }})
       } else {
         let arr: [i32; 4] = cast(self);
@@ -676,7 +676,7 @@ impl i32x4 {
         move_mask_m128(cast(self.sse))
       } else if #[cfg(target_feature="simd128")] {
         u32x4_bitmask(self.simd) as i32
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe
         {
           // set all to 1 if top bit is set, else 0
@@ -707,7 +707,7 @@ impl i32x4 {
         move_mask_m128(cast(self.sse)) != 0
       } else if #[cfg(target_feature="simd128")] {
         u32x4_bitmask(self.simd) != 0
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
         // some lanes are negative
         unsafe {
           vminvq_s32(self.neon) < 0
@@ -728,7 +728,7 @@ impl i32x4 {
         move_mask_m128(cast(self.sse)) == 0b1111
       } else if #[cfg(target_feature="simd128")] {
         u32x4_bitmask(self.simd) == 0b1111
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         // all lanes are negative
         unsafe {
           vmaxvq_s32(self.neon) < 0
