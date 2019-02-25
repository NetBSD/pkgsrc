$NetBSD: patch-gfx_webrender_src_query.rs,v 1.1 2019/02/25 15:32:24 wiz Exp $

--- gfx/webrender/src/query.rs.orig	2018-05-03 16:58:27.000000000 +0000
+++ gfx/webrender/src/query.rs
@@ -274,17 +274,20 @@ pub struct GpuMarker {
 
 impl GpuMarker {
     fn new(gl: &Rc<gl::Gl>, message: &str) -> Self {
+#[cfg(not(target_arch = "x86"))]
         gl.push_group_marker_ext(message);
         GpuMarker { gl: Rc::clone(gl) }
     }
 
     fn fire(gl: &Rc<gl::Gl>, message: &str) {
+#[cfg(not(target_arch = "x86"))]
         gl.insert_event_marker_ext(message);
     }
 }
 
 impl Drop for GpuMarker {
     fn drop(&mut self) {
+#[cfg(not(target_arch = "x86"))]
         self.gl.pop_group_marker_ext();
     }
 }
