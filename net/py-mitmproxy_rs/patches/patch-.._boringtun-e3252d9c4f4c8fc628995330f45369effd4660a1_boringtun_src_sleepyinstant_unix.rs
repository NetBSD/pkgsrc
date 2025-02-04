$NetBSD: patch-.._boringtun-e3252d9c4f4c8fc628995330f45369effd4660a1_boringtun_src_sleepyinstant_unix.rs,v 1.1 2025/02/04 12:10:02 adam Exp $

Add support for NetBSD.
https://github.com/cloudflare/boringtun/pull/386

--- ../boringtun-e3252d9c4f4c8fc628995330f45369effd4660a1/boringtun/src/sleepyinstant/unix.rs.orig	2024-01-01 23:15:11.332028854 +0000
+++ ../boringtun-e3252d9c4f4c8fc628995330f45369effd4660a1/boringtun/src/sleepyinstant/unix.rs
@@ -3,9 +3,9 @@ use std::time::Duration;
 use nix::sys::time::TimeSpec;
 use nix::time::{clock_gettime, ClockId};
 
-#[cfg(any(target_os = "macos", target_os = "ios"))]
+#[cfg(any(target_os = "macos", target_os = "ios", target_os = "netbsd"))]
 const CLOCK_ID: ClockId = ClockId::CLOCK_MONOTONIC;
-#[cfg(not(any(target_os = "macos", target_os = "ios")))]
+#[cfg(not(any(target_os = "macos", target_os = "ios", target_os = "netbsd")))]
 const CLOCK_ID: ClockId = ClockId::CLOCK_BOOTTIME;
 
 #[derive(Clone, Copy, Debug)]
