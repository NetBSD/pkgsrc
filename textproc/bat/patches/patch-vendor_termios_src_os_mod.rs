$NetBSD: patch-vendor_termios_src_os_mod.rs,v 1.1 2019/07/18 00:11:46 fox Exp $

Upstream PR is wip: https://github.com/dcuddeback/termios-rs/pull/22

--- ../vendor/termios-0.3.1/src/os/mod.rs.orig	2016-01-20 16:52:20.000000000 +0000
+++ ../vendor/termios-0.3.1/src/os/mod.rs
@@ -5,6 +5,7 @@
 #[cfg(target_os = "macos")] pub use self::macos as target;
 #[cfg(target_os = "freebsd")] pub use self::freebsd as target;
 #[cfg(target_os = "openbsd")] pub use self::openbsd as target;
+#[cfg(target_os = "netbsd")] pub use self::netbsd as target;
 #[cfg(target_os = "dragonfly")] pub use self::dragonfly as target;
 
 #[cfg(target_os = "linux")] pub mod linux;
@@ -12,4 +13,5 @@
 #[cfg(target_os = "macos")] pub mod macos;
 #[cfg(target_os = "freebsd")] pub mod freebsd;
 #[cfg(target_os = "openbsd")] pub mod openbsd;
+#[cfg(target_os = "netbsd")] pub mod netbsd;
 #[cfg(target_os = "dragonfly")] pub mod dragonfly;
