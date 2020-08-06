$NetBSD: patch-vendor_tokio-uds_src_ucred.rs,v 1.1 2020/08/06 11:42:56 jperkin Exp $

Support illumos.

--- vendor/tokio-uds/src/ucred.rs.orig	2020-07-13 18:18:17.000000000 +0000
+++ vendor/tokio-uds/src/ucred.rs
@@ -15,7 +15,7 @@ pub use self::impl_linux::get_peer_cred;
 #[cfg(any(target_os = "dragonfly", target_os = "macos", target_os = "ios", target_os = "freebsd", target_os = "netbsd", target_os = "openbsd"))]
 pub use self::impl_macos::get_peer_cred;
 
-#[cfg(any(target_os = "solaris"))]
+#[cfg(any(target_os = "illumos", target_os = "solaris"))]
 pub use self::impl_solaris::get_peer_cred;
 
 #[cfg(any(target_os = "linux", target_os = "android"))]
@@ -89,7 +89,7 @@ pub mod impl_macos {
 }
 
 
-#[cfg(any(target_os = "solaris"))]
+#[cfg(any(target_os = "illumos", target_os = "solaris"))]
 pub mod impl_solaris {
     use std::io;
     use std::os::unix::io::AsRawFd;
