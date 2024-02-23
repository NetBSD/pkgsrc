$NetBSD: patch-.._vendor_wgpu-0.19.1_src_lib.rs,v 1.1 2024/02/23 10:09:12 pin Exp $

Apply https://github.com/gfx-rs/wgpu/pull/5166

--- ../vendor/wgpu-0.19.1/src/lib.rs.orig	2024-02-21 19:24:28.317001076 +0000
+++ ../vendor/wgpu-0.19.1/src/lib.rs
@@ -2812,7 +2812,7 @@ pub struct CreateSurfaceError {
 enum CreateSurfaceErrorKind {
     /// Error from [`wgpu_hal`].
     #[cfg(wgpu_core)]
-    Hal(hal::InstanceError),
+    Hal(wgc::instance::CreateSurfaceError),
 
     /// Error from WebGPU surface creation.
     #[allow(dead_code)] // may be unused depending on target and features
@@ -2847,8 +2847,8 @@ impl error::Error for CreateSurfaceError
 }
 
 #[cfg(wgpu_core)]
-impl From<hal::InstanceError> for CreateSurfaceError {
-    fn from(e: hal::InstanceError) -> Self {
+impl From<wgc::instance::CreateSurfaceError> for CreateSurfaceError {
+    fn from(e: wgc::instance::CreateSurfaceError) -> Self {
         Self {
             inner: CreateSurfaceErrorKind::Hal(e),
         }
