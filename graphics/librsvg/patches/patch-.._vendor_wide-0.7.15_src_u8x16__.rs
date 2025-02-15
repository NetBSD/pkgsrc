$NetBSD: patch-.._vendor_wide-0.7.15_src_u8x16__.rs,v 1.1 2025/02/15 23:41:46 he Exp $

Do not try to use neon / SIMD on big-endian aarch64.

--- ../vendor/wide-0.7.15/src/u8x16_.rs.orig	2024-10-02 14:18:31.196265523 +0000
+++ ../vendor/wide-0.7.15/src/u8x16_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for u8x16 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -70,7 +70,7 @@ impl Add for u8x16 {
         Self { sse: add_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vaddq_u8(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -106,7 +106,7 @@ impl Sub for u8x16 {
         Self { sse: sub_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vsubq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -178,7 +178,7 @@ impl BitAnd for u8x16 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vandq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -214,7 +214,7 @@ impl BitOr for u8x16 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vorrq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -250,7 +250,7 @@ impl BitXor for u8x16 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: veorq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -290,7 +290,7 @@ impl u8x16 {
         Self { sse: cmp_eq_mask_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vceqq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -322,7 +322,7 @@ impl u8x16 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vbslq_u8(self.neon, t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -337,7 +337,7 @@ impl u8x16 {
         Self { sse: max_u8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_max(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vmaxq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -369,7 +369,7 @@ impl u8x16 {
         Self { sse: min_u8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_min(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vminq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -402,7 +402,7 @@ impl u8x16 {
         Self { sse: add_saturating_u8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_add_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe {Self { neon: vqaddq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -434,7 +434,7 @@ impl u8x16 {
         Self { sse: sub_saturating_u8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_sub_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64", target_endian = "little"))]{
         unsafe { Self { neon: vqsubq_u8(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -468,7 +468,7 @@ impl u8x16 {
             u8x16 { sse: unpack_low_i8_m128i(lhs.sse, rhs.sse) }
         } else if #[cfg(target_feature = "simd128")] {
           u8x16 { simd: u8x16_shuffle::<0, 16, 1, 17, 2, 18, 3, 19, 4, 20, 5, 21, 6, 22, 7, 23>(lhs.simd, rhs.simd) }
-        } else if #[cfg(all(target_feature = "neon", target_arch = "aarch64"))] {
+        } else if #[cfg(all(target_feature = "neon", target_arch = "aarch64", target_endian = "little"))] {
             let lhs = unsafe { vget_low_u8(lhs.neon) };
             let rhs = unsafe { vget_low_u8(rhs.neon) };
 
@@ -498,7 +498,7 @@ impl u8x16 {
             u8x16 { sse: unpack_high_i8_m128i(lhs.sse, rhs.sse) }
         } else if #[cfg(target_feature = "simd128")] {
             u8x16 { simd: u8x16_shuffle::<8, 24, 9, 25, 10, 26, 11, 27, 12, 28, 13, 29, 14, 30, 15, 31>(lhs.simd, rhs.simd) }
-        } else if #[cfg(all(target_feature = "neon", target_arch = "aarch64"))] {
+        } else if #[cfg(all(target_feature = "neon", target_arch = "aarch64", target_endian = "little"))] {
             let lhs = unsafe { vget_high_u8(lhs.neon) };
             let rhs = unsafe { vget_high_u8(rhs.neon) };
 
@@ -528,7 +528,7 @@ impl u8x16 {
             u8x16 { sse: pack_i16_to_u8_m128i(lhs.sse, rhs.sse) }
         } else if #[cfg(target_feature = "simd128")] {
             u8x16 { simd: u8x16_narrow_i16x8(lhs.simd, rhs.simd) }
-        } else if #[cfg(all(target_feature = "neon", target_arch = "aarch64"))] {
+        } else if #[cfg(all(target_feature = "neon", target_arch = "aarch64", target_endian = "little"))] {
             let lhs = unsafe { vqmovun_s16(lhs.neon) };
             let rhs = unsafe { vqmovun_s16(rhs.neon) };
             u8x16 { neon: unsafe { vcombine_u8(lhs, rhs) } }
