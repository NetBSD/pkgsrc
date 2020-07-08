$NetBSD: patch-vendor_mio_src_sys_unix_mod.rs,v 1.1 2020/07/08 14:46:14 jperkin Exp $

Support illumos.

--- vendor/mio/src/sys/unix/mod.rs.orig	2020-06-01 17:45:25.000000000 +0000
+++ vendor/mio/src/sys/unix/mod.rs
@@ -3,10 +3,10 @@ use libc::{self, c_int};
 #[macro_use]
 pub mod dlsym;
 
-#[cfg(any(target_os = "linux", target_os = "android", target_os = "solaris"))]
+#[cfg(any(target_os = "linux", target_os = "android", target_os = "solaris", target_os = "illumos"))]
 mod epoll;
 
-#[cfg(any(target_os = "linux", target_os = "android", target_os = "solaris"))]
+#[cfg(any(target_os = "linux", target_os = "android", target_os = "solaris", target_os = "illumos"))]
 pub use self::epoll::{Events, Selector};
 
 #[cfg(any(target_os = "bitrig", target_os = "dragonfly",
