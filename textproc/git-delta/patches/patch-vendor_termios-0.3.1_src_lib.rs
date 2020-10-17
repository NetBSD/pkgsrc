$NetBSD: patch-vendor_termios-0.3.1_src_lib.rs,v 1.1 2020/10/17 13:39:45 maya Exp $

NetBSD support, already upstream in termios 0.3.2

--- ../vendor/termios-0.3.1/src/lib.rs.orig	2018-03-26 21:22:45.000000000 +0000
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
