$NetBSD: patch-.._vendor_wide-0.7.30_src_u16x8__.rs,v 1.1 2025/09/23 11:12:16 adam Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.30/src/u16x8_.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/wide-0.7.30/src/u16x8_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for u16x8 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
       use core::arch::aarch64::*;
       #[repr(C)]
       #[derive(Copy, Clone)]
@@ -70,7 +70,7 @@ impl Add for u16x8 {
         Self { sse: add_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u16x8_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vaddq_u16(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -98,7 +98,7 @@ impl Sub for u16x8 {
         Self { sse: sub_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u16x8_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vsubq_u16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -126,7 +126,7 @@ impl Mul for u16x8 {
         Self { sse: mul_i16_keep_low_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u16x8_mul(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmulq_u16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -208,7 +208,7 @@ impl BitAnd for u16x8 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vandq_u16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -236,7 +236,7 @@ impl BitOr for u16x8 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vorrq_u16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -264,7 +264,7 @@ impl BitXor for u16x8 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: veorq_u16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -296,7 +296,7 @@ macro_rules! impl_shl_t_for_u16x8 {
             Self { sse: shl_all_u16_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: u16x8_shl(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
             unsafe {Self { neon: vshlq_u16(self.neon, vmovq_n_s16(rhs as i16)) }}
           } else {
             let u = rhs as u64;
@@ -332,7 +332,7 @@ macro_rules! impl_shr_t_for_u16x8 {
             Self { sse: shr_all_u16_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: u16x8_shr(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
             unsafe {Self { neon: vshlq_u16(self.neon, vmovq_n_s16( -(rhs as i16))) }}
           } else {
             let u = rhs as u64;
@@ -368,7 +368,7 @@ impl u16x8 {
         Self { sse: cmp_eq_mask_i16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u16x8_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vceqq_u16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -392,7 +392,7 @@ impl u16x8 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vbslq_u16(self.neon, t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -407,7 +407,7 @@ impl u16x8 {
         Self { sse: max_u16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u16x8_max(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmaxq_u16(self.neon, rhs.neon) }}
       } else {
         let arr: [u16; 8] = cast(self);
@@ -433,7 +433,7 @@ impl u16x8 {
         Self { sse: min_u16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u16x8_min(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminq_u16(self.neon, rhs.neon) }}
       } else {
         let arr: [u16; 8] = cast(self);
@@ -460,7 +460,7 @@ impl u16x8 {
         Self { sse: add_saturating_u16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u16x8_add_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vqaddq_u16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -484,7 +484,7 @@ impl u16x8 {
         Self { sse: sub_saturating_u16_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u16x8_sub_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vqsubq_u16(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -563,7 +563,7 @@ impl u16x8 {
           a: u32x4 { sse:unpack_low_i16_m128i(low, high) },
           b: u32x4 { sse:unpack_high_i16_m128i(low, high) }
         }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
          let lhs_low = unsafe { vget_low_u16(self.neon) };
          let rhs_low = unsafe { vget_low_u16(rhs.neon) };
 
@@ -598,7 +598,7 @@ impl u16x8 {
     pick! {
       if #[cfg(target_feature="sse2")] {
         Self { sse: mul_u16_keep_high_m128i(self.sse, rhs.sse) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))] {
         let lhs_low = unsafe { vget_low_u16(self.neon) };
         let rhs_low = unsafe { vget_low_u16(rhs.neon) };
 
