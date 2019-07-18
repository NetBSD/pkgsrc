$NetBSD: patch-vendor_termios_src_lib.rs,v 1.1 2019/07/18 00:11:46 fox Exp $

Upstream PR is wip: https://github.com/dcuddeback/termios-rs/pull/22

--- ../vendor/termios-0.3.1/src/lib.rs.orig	2016-01-20 16:52:20.000000000 +0000
+++ ../vendor/termios-0.3.1/src/lib.rs
@@ -99,6 +99,10 @@
 //!     cfsetspeed(termios, termios::os::openbsd::B921600)
 //! }
 //!
+//! #[cfg(target_os = "netbsd")]
+//! fn set_fastest_speed(termios: &mut Termios) -> io::Result<()> {
+//!     cfsetspeed(termios, termios::os::netbsd::B921600)
+//! }
 //! #[cfg(target_os = "dragonfly")]
 //! fn set_fastest_speed(termios: &mut Termios) -> io::Result<()> {
 //!     cfsetspeed(termios, termios::os::dragonfly::B230400)
