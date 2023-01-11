$NetBSD: patch-pgx_pgx-pg-sys_src_submodules_mod.rs,v 1.6 2023/01/11 03:33:46 tnn Exp $

NetBSD, SunOS support

--- ../vendor/pgx-pg-sys-0.6.1/src/submodules/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/pgx-pg-sys-0.6.1/src/submodules/mod.rs
@@ -45,10 +45,19 @@ extern "C" {
     ) -> std::os::raw::c_int;
 }
 
-#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "openbsd"))]
+#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "openbsd", target_os = "solaris", target_os = "illumos"))]
 extern "C" {
     pub(crate) fn sigsetjmp(
         env: *mut crate::sigjmp_buf,
         savemask: std::os::raw::c_int,
     ) -> std::os::raw::c_int;
 }
+
+#[cfg(target_os = "netbsd")]
+extern "C" {
+    #[link_name = "__sigsetjmp14"]
+    pub(crate) fn sigsetjmp(
+        env: *mut crate::sigjmp_buf,
+        savemask: std::os::raw::c_int,
+    ) -> std::os::raw::c_int;
+}
