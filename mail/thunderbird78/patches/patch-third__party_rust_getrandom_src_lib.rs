$NetBSD: patch-third__party_rust_getrandom_src_lib.rs,v 1.1 2023/02/05 08:32:24 he Exp $

--- third_party/rust/getrandom/src/lib.rs.orig	2020-08-28 21:33:54.000000000 +0000
+++ third_party/rust/getrandom/src/lib.rs
@@ -17,7 +17,7 @@
 //! | macOS, iOS       | [`SecRandomCopyBytes`][4]
 //! | FreeBSD          | [`kern.arandom`][5]
 //! | OpenBSD, Bitrig  | [`getentropy`][6]
-//! | NetBSD           | [`/dev/urandom`][7] after reading from `/dev/random` once
+//! | NetBSD           | [`kern.arandom`][5]
 //! | Dragonfly BSD    | [`/dev/random`][8]
 //! | Solaris, illumos | [`getrandom`][9] system call if available, otherwise [`/dev/random`][10]
 //! | Fuchsia OS       | [`cprng_draw`][11]
@@ -184,7 +184,7 @@ mod_use!(cfg(target_os = "illumos"), sol
 mod_use!(cfg(target_os = "ios"), macos);
 mod_use!(cfg(target_os = "linux"), linux_android);
 mod_use!(cfg(target_os = "macos"), macos);
-mod_use!(cfg(target_os = "netbsd"), use_file);
+mod_use!(cfg(target_os = "netbsd"), freebsd);
 mod_use!(cfg(target_os = "openbsd"), openbsd_bitrig);
 mod_use!(cfg(target_os = "redox"), use_file);
 mod_use!(cfg(target_os = "solaris"), solaris_illumos);
