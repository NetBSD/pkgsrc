$NetBSD: patch-vendor_faster-hex-0.8.0_src_lib.rs,v 1.1 2023/09/03 17:00:18 he Exp $

Unify conditions for vectorization_support() use and definition.

--- ../vendor/faster-hex-0.8.0/src/lib.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/faster-hex-0.8.0/src/lib.rs
@@ -43,7 +43,8 @@ pub(crate) enum Vectorization {
 
 #[inline(always)]
 pub(crate) fn vectorization_support() -> Vectorization {
-    #[cfg(all(any(target_arch = "x86", target_arch = "x86_64")))]
+    #[cfg(all(any(target_arch = "x86", target_arch = "x86_64"),
+              target_feature = "sse"))]
     {
         use core::sync::atomic::{AtomicU8, Ordering};
         static FLAGS: AtomicU8 = AtomicU8::new(u8::MAX);
