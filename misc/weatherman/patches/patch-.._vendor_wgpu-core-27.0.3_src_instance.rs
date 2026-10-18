$NetBSD: patch-.._vendor_wgpu-core-27.0.3_src_instance.rs,v 1.1 2026/10/18 13:05:42 pin Exp $

Backport #8695 and #10316 to wgpu v27 series.

--- ../vendor/wgpu-core-27.0.3/src/instance.rs.orig	2026-10-17 11:32:34.258462046 +0000
+++ ../vendor/wgpu-core-27.0.3/src/instance.rs
@@ -101,7 +101,7 @@ impl Instance {
             flags: instance_desc.flags,
         };
 
-        #[cfg(vulkan)]
+        #[cfg(all(vulkan, not(target_os = "netbsd")))]
         this.try_add_hal(hal::api::Vulkan, instance_desc);
         #[cfg(metal)]
         this.try_add_hal(hal::api::Metal, instance_desc);
@@ -251,7 +251,12 @@ impl Instance {
     ///
     /// This function is only available on non-apple Unix-like platforms (Linux, FreeBSD) and
     /// currently only works with the Vulkan backend.
-    #[cfg(all(unix, not(target_vendor = "apple"), not(target_family = "wasm")))]
+    #[cfg(all(
+        unix,
+        not(target_vendor = "apple"),
+        not(target_family = "wasm"),
+        not(target_os = "netbsd")
+    ))]
     #[cfg_attr(not(vulkan), expect(unused_variables))]
     pub unsafe fn create_surface_from_drm(
         &self,
@@ -268,7 +273,7 @@ impl Instance {
         let mut surface_per_backend: HashMap<Backend, Box<dyn hal::DynSurface>> =
             HashMap::default();
 
-        #[cfg(vulkan)]
+        #[cfg(all(vulkan, not(target_os = "netbsd")))]
         {
             let instance = unsafe { self.as_hal::<hal::api::Vulkan>() }
                 .ok_or(CreateSurfaceError::BackendNotEnabled(Backend::Vulkan))?;
@@ -926,7 +931,12 @@ impl Global {
     ///
     /// This function is only available on non-apple Unix-like platforms (Linux, FreeBSD) and
     /// currently only works with the Vulkan backend.
-    #[cfg(all(unix, not(target_vendor = "apple"), not(target_family = "wasm")))]
+    #[cfg(all(
+        unix,
+        not(target_vendor = "apple"),
+        not(target_family = "wasm"),
+        not(target_os = "netbsd")
+    ))]
     pub unsafe fn instance_create_surface_from_drm(
         &self,
         fd: i32,
