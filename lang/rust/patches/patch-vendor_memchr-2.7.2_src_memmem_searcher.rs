$NetBSD: patch-vendor_memchr-2.7.2_src_memmem_searcher.rs,v 1.1 2024/10/13 19:04:40 he Exp $

Skip attempts at using neon on big-endian aarch64.
Ref. https://github.com/rust-lang/rust/issues/129819

--- vendor/memchr-2.7.2/src/memmem/searcher.rs.orig	2024-09-01 10:22:12.705269507 +0000
+++ vendor/memchr-2.7.2/src/memmem/searcher.rs
@@ -3,7 +3,7 @@ use crate::arch::all::{
     rabinkarp, twoway,
 };
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 use crate::arch::aarch64::neon::packedpair as neon;
 #[cfg(all(target_arch = "wasm32", target_feature = "simd128"))]
 use crate::arch::wasm32::simd128::packedpair as simd128;
@@ -129,7 +129,7 @@ impl Searcher {
                 Searcher::twoway(needle, rabinkarp, prestrat)
             }
         }
-        #[cfg(target_arch = "aarch64")]
+        #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
         {
             if let Some(pp) = neon::Finder::with_pair(needle, pair) {
                 if do_packed_search(needle) {
@@ -152,7 +152,7 @@ impl Searcher {
         #[cfg(not(any(
             all(target_arch = "x86_64", target_feature = "sse2"),
             all(target_arch = "wasm32", target_feature = "simd128"),
-            target_arch = "aarch64"
+            all(target_arch = "aarch64", target_endian = "little")
         )))]
         {
             if prefilter.is_none() {
@@ -253,7 +253,7 @@ union SearcherKind {
     avx2: crate::arch::x86_64::avx2::packedpair::Finder,
     #[cfg(all(target_arch = "wasm32", target_feature = "simd128"))]
     simd128: crate::arch::wasm32::simd128::packedpair::Finder,
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     neon: crate::arch::aarch64::neon::packedpair::Finder,
 }
 
@@ -421,7 +421,7 @@ unsafe fn searcher_kind_simd128(
 /// # Safety
 ///
 /// Callers must ensure that the `searcher.kind.neon` union field is set.
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 unsafe fn searcher_kind_neon(
     searcher: &Searcher,
     _prestate: &mut PrefilterState,
@@ -686,7 +686,7 @@ impl Prefilter {
     }
 
     /// Return a prefilter using a aarch64 neon vector algorithm.
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     #[inline]
     fn neon(finder: neon::Finder, needle: &[u8]) -> Prefilter {
         trace!("building aarch64 neon prefilter");
@@ -763,7 +763,7 @@ union PrefilterKind {
     avx2: crate::arch::x86_64::avx2::packedpair::Finder,
     #[cfg(all(target_arch = "wasm32", target_feature = "simd128"))]
     simd128: crate::arch::wasm32::simd128::packedpair::Finder,
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     neon: crate::arch::aarch64::neon::packedpair::Finder,
 }
 
@@ -852,7 +852,7 @@ unsafe fn prefilter_kind_simd128(
 /// # Safety
 ///
 /// Callers must ensure that the `strat.kind.neon` union field is set.
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 unsafe fn prefilter_kind_neon(
     strat: &Prefilter,
     haystack: &[u8],
