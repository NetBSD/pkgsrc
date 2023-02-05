$NetBSD: patch-third__party_rust_authenticator_src_lib.rs,v 1.1 2023/02/05 08:32:24 he Exp $

--- third_party/rust/authenticator/src/lib.rs.orig	2020-08-28 21:33:54.000000000 +0000
+++ third_party/rust/authenticator/src/lib.rs
@@ -5,7 +5,7 @@
 #[macro_use]
 mod util;
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(any(target_os = "linux", target_os = "freebsd", target_os = "netbsd"))]
 pub mod hidproto;
 
 #[cfg(any(target_os = "linux"))]
@@ -22,6 +22,10 @@ extern crate devd_rs;
 #[path = "freebsd/mod.rs"]
 pub mod platform;
 
+#[cfg(any(target_os = "netbsd"))]
+#[path = "netbsd/mod.rs"]
+pub mod platform;
+
 #[cfg(any(target_os = "openbsd"))]
 #[path = "openbsd/mod.rs"]
 pub mod platform;
@@ -41,6 +45,7 @@ pub mod platform;
     target_os = "linux",
     target_os = "freebsd",
     target_os = "openbsd",
+    target_os = "netbsd",
     target_os = "macos",
     target_os = "windows"
 )))]
