$NetBSD: patch-pgx_pgx-pg-sys_src_submodules_mod.rs,v 1.2 2021/12/10 11:44:19 tnn Exp $

NetBSD support

--- ../vendor/pgx-pg-sys-0.2.0/src/submodules/mod.rs.orig	1973-11-29 21:33:09.000000000 +0000
+++ ../vendor/pgx-pg-sys-0.2.0/src/submodules/mod.rs
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
 #[cfg(any(target_os = "macos", target_os = "freebsd"))]
 extern "C" {
     pub(crate) fn sigsetjmp(
