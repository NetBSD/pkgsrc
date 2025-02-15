$NetBSD: patch-.._vendor_wide-0.7.15_src_i16x8__.rs,v 1.1 2025/02/15 23:41:46 he Exp $

Do not try to use neon / SIMD on big-endian aarch64.

--- ../vendor/wide-0.7.15/src/i16x8_.rs.orig	2024-10-02 14:06:08.049939294 +0000
+++ ../vendor/wide-0.7.15/src/i16x8_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for i16x8 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -70,7 +70,7 @@ impl Add for i16x8 {
         Self { sse: add_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vaddq_s16(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -98,7 +98,7 @@ impl Sub for i16x8 {
         Self { sse: sub_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vsubq_s16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -126,7 +126,7 @@ impl Mul for i16x8 {
         Self { sse: mul_i16_keep_low_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_mul(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vmulq_s16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -208,7 +208,7 @@ impl BitAnd for i16x8 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vandq_s16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -236,7 +236,7 @@ impl BitOr for i16x8 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vorrq_s16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -264,7 +264,7 @@ impl BitXor for i16x8 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: veorq_s16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -296,7 +296,7 @@ macro_rules! impl_shl_t_for_i16x8 {
             Self { sse: shl_all_u16_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: i16x8_shl(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
             unsafe {Self { neon: vshlq_s16(self.neon, vmovq_n_s16(rhs as i16)) }}
           } else {
             let u = rhs as u64;
@@ -332,7 +332,7 @@ macro_rules! impl_shr_t_for_i16x8 {
             Self { sse: shr_all_i16_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: i16x8_shr(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
             unsafe {Self { neon: vshlq_s16(self.neon, vmovq_n_s16( -(rhs as i16))) }}
           } else {
             let u = rhs as u64;
@@ -364,7 +364,7 @@ impl CmpEq for i16x8 {
         Self { sse: cmp_eq_mask_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s16_u16(vceqq_s16(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -392,7 +392,7 @@ impl CmpGt for i16x8 {
         Self { sse: cmp_gt_mask_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s16_u16(vcgtq_s16(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -420,7 +420,7 @@ impl CmpLt for i16x8 {
         Self { sse: cmp_lt_mask_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s16_u16(vcltq_s16(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -453,7 +453,7 @@ impl i16x8 {
         move_mask_i8_m128i( pack_i16_to_i8_m128i(self.sse,self.sse)) & 0xff
       } else if #[cfg(target_feature="simd128")] {
         i16x8_bitmask(self.simd) as i32
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe
         {
           // set all to 1 if top bit is set, else 0
@@ -550,7 +550,7 @@ impl i16x8 {
         use core::arch::wasm32::*;
 
         i16x8 { simd: i16x8_narrow_i32x4(v.a.simd, v.b.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))] {
         use core::arch::aarch64::*;
 
         unsafe {
@@ -620,7 +620,7 @@ impl i16x8 {
         unsafe { Self { sse: load_unaligned_m128i( &*(input.as_ptr() as * const [u8;16]) ) } }
       } else if #[cfg(target_feature="simd128")] {
         unsafe { Self { simd: v128_load(input.as_ptr() as *const v128 ) } }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vld1q_s16( input.as_ptr() as *const i16 ) } }
       } else {
         // 2018 edition doesn't have try_into
@@ -637,7 +637,7 @@ impl i16x8 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vbslq_s16(vreinterpretq_u16_s16(self.neon), t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -693,7 +693,7 @@ impl i16x8 {
         Self { sse: abs_i16_m128i(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vabsq_s16(self.neon) }}
       } else {
         self.is_negative().blend(self.neg(), self)
@@ -708,7 +708,7 @@ impl i16x8 {
         Self { sse: max_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_max(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vmaxq_s16(self.neon, rhs.neon) }}
       } else {
         self.cmp_lt(rhs).blend(rhs, self)
@@ -723,7 +723,7 @@ impl i16x8 {
         Self { sse: min_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_min(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vminq_s16(self.neon, rhs.neon) }}
       } else {
         self.cmp_lt(rhs).blend(self, rhs)
@@ -739,7 +739,7 @@ impl i16x8 {
         Self { sse: add_saturating_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_add_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vqaddq_s16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -763,7 +763,7 @@ impl i16x8 {
         Self { sse: sub_saturating_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_sub_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vqsubq_s16(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -792,7 +792,7 @@ impl i16x8 {
         i32x4 { sse:  mul_i16_horizontal_add_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         i32x4 { simd: i32x4_dot_i16x8(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {
           let pl = vmull_s16(vget_low_s16(self.neon),  vget_low_s16(rhs.neon));
           let ph = vmull_high_s16(self.neon, rhs.neon);
@@ -835,7 +835,7 @@ impl i16x8 {
         Self { sse: s }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_q15mulr_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vqrdmulhq_s16(self.neon, rhs.neon) } }
       } else {
         // compiler does a surprisingly good job of vectorizing this
@@ -887,7 +887,7 @@ impl i16x8 {
           i16x8 { sse: unpack_low_i64_m128i(b4, b8) },
           i16x8 { sse: unpack_high_i64_m128i(b4, b8) } ,
         ]
-     } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+     } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
 
           #[inline] fn vtrq32(a : int16x8_t, b : int16x8_t) -> (int16x8_t, int16x8_t)
           {
@@ -1015,7 +1015,7 @@ impl i16x8 {
         Self { sse: s }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i16x8_q15mulr_sat(self.simd, i16x8_splat(rhs)) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vqrdmulhq_n_s16(self.neon, rhs) } }
       } else {
         // compiler does a surprisingly good job of vectorizing this
