$NetBSD: patch-pgx_pgx-pg-sys_src_submodules_mod.rs,v 1.3 2022/03/27 14:05:36 tnn Exp $

NetBSD, SunOS support

--- ../vendor/pgx-pg-sys-0.2.0/src/submodules/mod.rs.orig	1973-11-29 21:33:09.000000000 +0000
+++ ../vendor/pgx-pg-sys-0.2.0/src/submodules/mod.rs
@@ -20,7 +20,16 @@ extern "C" {
     ) -> std::os::raw::c_int;
 }
 
-#[cfg(any(target_os = "macos", target_os = "freebsd"))]
+#[cfg(target_os = "netbsd")]
+extern "C" {
+    #[link_name = "__sigsetjmp14"]
+    pub(crate) fn sigsetjmp(
+        env: *mut crate::sigjmp_buf,
+        savemask: std::os::raw::c_int,
+    ) -> std::os::raw::c_int;
+}
+
+#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "solaris", target_os = "illumos"))]
 extern "C" {
     pub(crate) fn sigsetjmp(
         env: *mut crate::sigjmp_buf,
