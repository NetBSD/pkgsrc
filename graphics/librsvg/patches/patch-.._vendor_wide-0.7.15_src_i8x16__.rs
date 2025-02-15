$NetBSD: patch-.._vendor_wide-0.7.15_src_i8x16__.rs,v 1.1 2025/02/15 23:41:46 he Exp $

Do not try to use neon / SIMD on big-endian aarch64.

--- ../vendor/wide-0.7.15/src/i8x16_.rs.orig	2024-10-02 14:11:05.334444151 +0000
+++ ../vendor/wide-0.7.15/src/i8x16_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for i8x16 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -70,7 +70,7 @@ impl Add for i8x16 {
         Self { sse: add_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vaddq_s8(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -106,7 +106,7 @@ impl Sub for i8x16 {
         Self { sse: sub_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vsubq_s8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -178,7 +178,7 @@ impl BitAnd for i8x16 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vandq_s8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -214,7 +214,7 @@ impl BitOr for i8x16 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vorrq_s8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -250,7 +250,7 @@ impl BitXor for i8x16 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: veorq_s8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -286,7 +286,7 @@ impl CmpEq for i8x16 {
         Self { sse: cmp_eq_mask_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s8_u8(vceqq_s8(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -322,7 +322,7 @@ impl CmpGt for i8x16 {
         Self { sse: cmp_gt_mask_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_gt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s8_u8(vcgtq_s8(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -358,7 +358,7 @@ impl CmpLt for i8x16 {
         Self { sse: cmp_lt_mask_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_lt(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vreinterpretq_s8_u8(vcltq_s8(self.neon, rhs.neon)) }}
       } else {
         Self { arr: [
@@ -400,7 +400,7 @@ impl i8x16 {
         i8x16 { sse: pack_i16_to_i8_m128i( extract_m128i_from_m256i::<0>(v.avx2), extract_m128i_from_m256i::<1>(v.avx2))  }
       } else if #[cfg(target_feature="sse2")] {
         i8x16 { sse: pack_i16_to_i8_m128i( v.a.sse, v.b.sse ) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))] {
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))] {
         use core::arch::aarch64::*;
 
         unsafe {
@@ -487,7 +487,7 @@ impl i8x16 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vbslq_s8(vreinterpretq_u8_s8(self.neon), t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -502,7 +502,7 @@ impl i8x16 {
         Self { sse: abs_i8_m128i(self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_abs(self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vabsq_s8(self.neon) }}
       } else {
         let arr: [i8; 16] = cast(self);
@@ -535,7 +535,7 @@ impl i8x16 {
         Self { sse: max_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_max(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vmaxq_s8(self.neon, rhs.neon) }}
       } else {
         self.cmp_lt(rhs).blend(rhs, self)
@@ -550,7 +550,7 @@ impl i8x16 {
         Self { sse: min_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_min(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vminq_s8(self.neon, rhs.neon) }}
       } else {
         self.cmp_lt(rhs).blend(self, rhs)
@@ -568,7 +568,7 @@ impl i8x16 {
         unsafe { Self { sse: load_unaligned_m128i( &*(input.as_ptr() as * const [u8;16]) ) } }
       } else if #[cfg(target_feature="simd128")] {
         unsafe { Self { simd: v128_load(input.as_ptr() as *const v128 ) } }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vld1q_s8( input.as_ptr() as *const i8 ) } }
       } else {
         // 2018 edition doesn't have try_into
@@ -585,7 +585,7 @@ impl i8x16 {
         move_mask_i8_m128i(self.sse)
       } else if #[cfg(target_feature="simd128")] {
         i8x16_bitmask(self.simd) as i32
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe
         {
           // set all to 1 if top bit is set, else 0
@@ -666,7 +666,7 @@ impl i8x16 {
         Self { sse: add_saturating_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_add_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vqaddq_s8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -698,7 +698,7 @@ impl i8x16 {
         Self { sse: sub_saturating_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: i8x16_sub_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vqsubq_s8(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
