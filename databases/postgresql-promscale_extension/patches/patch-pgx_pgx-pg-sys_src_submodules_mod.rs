$NetBSD: patch-pgx_pgx-pg-sys_src_submodules_mod.rs,v 1.1 2021/08/25 11:06:28 tnn Exp $

NetBSD support

--- pgx/pgx-pg-sys/src/submodules/mod.rs.orig	2021-04-14 16:14:29.000000000 +0000
+++ pgx/pgx-pg-sys/src/submodules/mod.rs
@@ -20,6 +20,15 @@ extern "C" {
     ) -> std::os::raw::c_int;
 }
 
+#[cfg(target_os = "netbsd")]
+extern "C" {
+    #[link_name = "__sigsetjmp14"]
+    pub(crate) fn sigsetjmp(
+        env: *mut crate::sigjmp_buf,
+        savemask: std::os::raw::c_int,
+    ) -> std::os::raw::c_int;
+}
+
 #[cfg(target_os = "macos")]
 extern "C" {
     pub(crate) fn sigsetjmp(
