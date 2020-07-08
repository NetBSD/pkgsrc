$NetBSD: patch-vendor_net2_src_lib.rs,v 1.1 2020/07/08 14:46:14 jperkin Exp $

Support illumos.

--- vendor/net2/src/lib.rs.orig	2020-06-01 17:45:25.000000000 +0000
+++ vendor/net2/src/lib.rs
@@ -63,7 +63,7 @@ mod utils;
 #[cfg(target_os="redox")] #[path = "sys/redox/mod.rs"] mod sys;
 #[cfg(unix)] #[path = "sys/unix/mod.rs"] mod sys;
 #[cfg(windows)] #[path = "sys/windows/mod.rs"] mod sys;
-#[cfg(all(unix, not(any(target_os = "solaris"))))] pub mod unix;
+#[cfg(all(unix, not(any(target_os = "solaris", target_os = "illumos"))))] pub mod unix;
 
 pub use tcp::TcpBuilder;
 pub use udp::UdpBuilder;
