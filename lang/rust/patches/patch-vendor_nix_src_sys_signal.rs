$NetBSD: patch-vendor_nix_src_sys_signal.rs,v 1.4 2023/10/25 05:50:43 pin Exp $

Narrow the conditional on mips to only apply to Linux.

--- vendor/nix/src/sys/signal.rs.orig	2023-01-25 01:49:16.000000000 +0000
+++ vendor/nix/src/sys/signal.rs
@@ -1069,7 +1069,7 @@ mod sigevent {
                 SigevNotify::SigevThreadId{..} => libc::SIGEV_THREAD_ID,
                 #[cfg(all(target_os = "linux", target_env = "uclibc"))]
                 SigevNotify::SigevThreadId{..} => libc::SIGEV_THREAD_ID,
-                #[cfg(any(all(target_os = "linux", target_env = "musl"), target_arch = "mips"))]
+                #[cfg(all(target_os = "linux", target_env = "musl", target_arch = "mips"))]
                 SigevNotify::SigevThreadId{..} => 4  // No SIGEV_THREAD_ID defined
             };
             sev.sigev_signo = match sigev_notify {
