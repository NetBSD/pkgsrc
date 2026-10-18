$NetBSD: patch-.._vendor_wgpu-27.0.1_src_backend_wgpu_core.rs,v 1.1 2026/10/18 13:05:41 pin Exp $

Backport #8695 and #10316 to wgpu v27 series.

--- ../vendor/wgpu-27.0.1/src/backend/wgpu_core.rs.orig	2026-10-17 11:41:08.836901782 +0000
+++ ../vendor/wgpu-27.0.1/src/backend/wgpu_core.rs
@@ -797,7 +797,12 @@ impl dispatch::InstanceInterface for ContextWgpuCore {
                     .instance_create_surface(raw_display_handle, raw_window_handle, None)
             },
 
-            #[cfg(all(unix, not(target_vendor = "apple"), not(target_family = "wasm")))]
+            #[cfg(all(
+                unix,
+                not(target_vendor = "apple"),
+                not(target_family = "wasm"),
+                not(target_os = "netbsd")
+            ))]
             SurfaceTargetUnsafe::Drm {
                 fd,
                 plane,
@@ -821,6 +826,11 @@ impl dispatch::InstanceInterface for ContextWgpuCore {
             SurfaceTargetUnsafe::CoreAnimationLayer(layer) => unsafe {
                 self.0.instance_create_surface_metal(layer, None)
             },
+
+            #[cfg(target_os = "netbsd")]
+            SurfaceTargetUnsafe::Drm { .. } => Err(
+                wgc::instance::CreateSurfaceError::BackendNotEnabled(wgt::Backend::Vulkan),
+            ),
 
             #[cfg(dx12)]
             SurfaceTargetUnsafe::CompositionVisual(visual) => unsafe {
