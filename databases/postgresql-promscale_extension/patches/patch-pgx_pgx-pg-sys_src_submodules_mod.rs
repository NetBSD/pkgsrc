$NetBSD: patch-pgx_pgx-pg-sys_src_submodules_mod.rs,v 1.5 2022/09/04 11:55:41 tnn Exp $

NetBSD, SunOS support

--- ../pgx/pgx-pg-sys/src/submodules/mod.rs.orig	2022-07-26 13:03:15.000000000 +0000
+++ ../pgx/pgx-pg-sys/src/submodules/mod.rs
@@ -27,10 +27,19 @@ extern "C" {
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
