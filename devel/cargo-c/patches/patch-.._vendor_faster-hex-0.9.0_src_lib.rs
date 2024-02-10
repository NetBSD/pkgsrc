$NetBSD: patch-.._vendor_faster-hex-0.9.0_src_lib.rs,v 1.1 2024/02/10 21:46:04 pin Exp $

Unify conditions for vectorization_support() use and definition.

--- ../vendor/faster-hex-0.9.0/src/lib.rs.orig	2024-02-10 21:16:02.053719873 +0000
+++ ../vendor/faster-hex-0.9.0/src/lib.rs
@@ -43,7 +43,7 @@ pub(crate) enum Vectorization {
 
 #[inline(always)]
 pub(crate) fn vectorization_support() -> Vectorization {
-    #[cfg(all(any(target_arch = "x86", target_arch = "x86_64")))]
+    #[cfg(all(any(target_arch = "x86", target_arch = "x86_64"), target_feature = "sse"))]
     {
         use core::sync::atomic::{AtomicU8, Ordering};
         static FLAGS: AtomicU8 = AtomicU8::new(u8::MAX);
