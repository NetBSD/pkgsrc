$NetBSD: patch-.._boringtun-2f3c85f5c4a601018c10b464b1ca890d9504bf6e_boringtun_src_sleepyinstant_unix.rs,v 1.1 2025/08/21 14:07:07 adam Exp $

Add support for NetBSD.
https://github.com/cloudflare/boringtun/pull/386

--- ../boringtun-2f3c85f5c4a601018c10b464b1ca890d9504bf6e/boringtun/src/sleepyinstant/unix.rs.orig	2025-08-21 13:58:11.761856641 +0000
+++ ../boringtun-2f3c85f5c4a601018c10b464b1ca890d9504bf6e/boringtun/src/sleepyinstant/unix.rs
@@ -7,6 +7,7 @@ use nix::time::{clock_gettime, ClockId};
     target_os = "macos",
     target_os = "ios",
     target_os = "tvos",
+    target_os = "netbsd",
     target_os = "freebsd"
 ))]
 const CLOCK_ID: ClockId = ClockId::CLOCK_MONOTONIC;
@@ -14,6 +15,7 @@ const CLOCK_ID: ClockId = ClockId::CLOCK
     target_os = "macos",
     target_os = "ios",
     target_os = "tvos",
+    target_os = "netbsd",
     target_os = "freebsd"
 )))]
 const CLOCK_ID: ClockId = ClockId::CLOCK_BOOTTIME;
