$NetBSD: patch-.._vendor_wgpu-core-0.19.0_src_instance.rs,v 1.1 2024/02/23 10:09:12 pin Exp $

Apply https://github.com/gfx-rs/wgpu/pull/5166

--- ../vendor/wgpu-core-0.19.0/src/instance.rs.orig	2024-02-21 19:18:58.413091905 +0000
+++ ../vendor/wgpu-core-0.19.0/src/instance.rs
@@ -467,6 +467,15 @@ pub enum RequestAdapterError {
     InvalidSurface(SurfaceId),
 }
 
+#[derive(Clone, Debug, Error)]
+#[non_exhaustive]
+pub enum CreateSurfaceError {
+    #[error("No backend is available")]
+    NoSupportedBackend,
+    #[error(transparent)]
+    InstanceError(#[from] hal::InstanceError),
+}
+
 impl<G: GlobalIdentityHandlerFactory> Global<G> {
     /// # Safety
     ///
@@ -479,7 +488,7 @@ impl<G: GlobalIdentityHandlerFactory> Gl
         display_handle: raw_window_handle::RawDisplayHandle,
         window_handle: raw_window_handle::RawWindowHandle,
         id_in: Input<G, SurfaceId>,
-    ) -> Result<SurfaceId, hal::InstanceError> {
+    ) -> Result<SurfaceId, CreateSurfaceError> {
         profiling::scope!("Instance::create_surface");
 
         fn init<A: HalApi>(
@@ -517,8 +526,7 @@ impl<G: GlobalIdentityHandlerFactory> Gl
             hal_surface = init::<hal::api::Gles>(&self.instance.gl, display_handle, window_handle);
         }
 
-        //  This is only None if there's no instance at all.
-        let hal_surface = hal_surface.unwrap()?;
+        let hal_surface = hal_surface.ok_or(CreateSurfaceError::NoSupportedBackend)??;
 
         let surface = Surface {
             presentation: Mutex::new(None),
