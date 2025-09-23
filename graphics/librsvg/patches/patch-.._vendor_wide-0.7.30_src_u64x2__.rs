$NetBSD: patch-.._vendor_wide-0.7.30_src_u64x2__.rs,v 1.1 2025/09/23 11:12:16 adam Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.30/src/u64x2_.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/wide-0.7.30/src/u64x2_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for u64x2 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -72,7 +72,7 @@ impl Add for u64x2 {
         Self { sse: add_i64_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u64x2_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vaddq_u64(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -94,7 +94,7 @@ impl Sub for u64x2 {
         Self { sse: sub_i64_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u64x2_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vsubq_u64(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -191,7 +191,7 @@ impl BitAnd for u64x2 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vandq_u64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -213,7 +213,7 @@ impl BitOr for u64x2 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vorrq_u64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -235,7 +235,7 @@ impl BitXor for u64x2 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: veorq_u64(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -261,7 +261,7 @@ macro_rules! impl_shl_t_for_u64x2 {
             Self { sse: shl_all_u64_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: u64x2_shl(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
             unsafe {Self { neon: vshlq_u64(self.neon, vmovq_n_s64(rhs as i64)) }}
           } else {
             let u = rhs as u64;
@@ -291,7 +291,7 @@ macro_rules! impl_shr_t_for_u64x2 {
             Self { sse: shr_all_u64_m128i(self.sse, shift) }
           } else if #[cfg(target_feature="simd128")] {
             Self { simd: u64x2_shr(self.simd, rhs as u32) }
-          } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+          } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
             unsafe {Self { neon: vshlq_u64(self.neon, vmovq_n_s64(-(rhs as i64))) }}
           } else {
             let u = rhs as u64;
@@ -321,7 +321,7 @@ impl u64x2 {
         Self { sse: cmp_eq_mask_i64_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u64x2_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vceqq_u64(self.neon, rhs.neon) } }
       } else {
         let s: [u64;2] = cast(self);
@@ -341,7 +341,7 @@ impl u64x2 {
         // no unsigned gt so inverting the high bit will get the correct result
         let highbit = u64x2::splat(1 << 63);
         Self { sse: cmp_gt_mask_i64_m128i((self ^ highbit).sse, (rhs ^ highbit).sse) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vcgtq_u64(self.neon, rhs.neon) }}
       } else {
         // u64x2_gt on WASM is not a thing. https://github.com/WebAssembly/simd/pull/414
@@ -370,7 +370,7 @@ impl u64x2 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vbslq_u64(self.neon, t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
