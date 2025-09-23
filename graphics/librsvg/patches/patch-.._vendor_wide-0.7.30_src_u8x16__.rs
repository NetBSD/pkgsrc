$NetBSD: patch-.._vendor_wide-0.7.30_src_u8x16__.rs,v 1.1 2025/09/23 11:12:16 adam Exp $

Do not try to use neon / SIMD in big-endian mode on aarch64.

--- ../vendor/wide-0.7.30/src/u8x16_.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/wide-0.7.30/src/u8x16_.rs
@@ -25,7 +25,7 @@ pick! {
     }
 
     impl Eq for u8x16 { }
-  } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+  } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
     use core::arch::aarch64::*;
     #[repr(C)]
     #[derive(Copy, Clone)]
@@ -70,7 +70,7 @@ impl Add for u8x16 {
         Self { sse: add_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_add(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vaddq_u8(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
@@ -106,7 +106,7 @@ impl Sub for u8x16 {
         Self { sse: sub_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_sub(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vsubq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -178,7 +178,7 @@ impl BitAnd for u8x16 {
         Self { sse: bitand_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_and(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vandq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -214,7 +214,7 @@ impl BitOr for u8x16 {
         Self { sse: bitor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_or(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vorrq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -250,7 +250,7 @@ impl BitXor for u8x16 {
         Self { sse: bitxor_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_xor(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: veorq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -290,7 +290,7 @@ impl u8x16 {
         Self { sse: cmp_eq_mask_i8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_eq(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vceqq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -322,7 +322,7 @@ impl u8x16 {
         Self { sse: blend_varying_i8_m128i(f.sse, t.sse, self.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: v128_bitselect(t.simd, f.simd, self.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vbslq_u8(self.neon, t.neon, f.neon) }}
       } else {
         generic_bit_blend(self, t, f)
@@ -337,7 +337,7 @@ impl u8x16 {
         Self { sse: max_u8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_max(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vmaxq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -369,7 +369,7 @@ impl u8x16 {
         Self { sse: min_u8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_min(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vminq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -402,7 +402,7 @@ impl u8x16 {
         Self { sse: add_saturating_u8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_add_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe {Self { neon: vqaddq_u8(self.neon, rhs.neon) }}
       } else {
         Self { arr: [
@@ -434,7 +434,7 @@ impl u8x16 {
         Self { sse: sub_saturating_u8_m128i(self.sse, rhs.sse) }
       } else if #[cfg(target_feature="simd128")] {
         Self { simd: u8x16_sub_sat(self.simd, rhs.simd) }
-      } else if #[cfg(all(target_feature="neon",target_arch="aarch64"))]{
+      } else if #[cfg(all(target_feature="neon",target_arch="aarch64",target_endian="little"))]{
         unsafe { Self { neon: vqsubq_u8(self.neon, rhs.neon) } }
       } else {
         Self { arr: [
