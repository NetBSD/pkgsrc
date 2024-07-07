$NetBSD: patch-vendor_nix-0.26.2_src_sys_signal.rs,v 1.1 2024/07/07 10:41:22 wiz Exp $

Narrow the conditional on mips to only apply to Linux.

--- vendor/nix-0.26.2/src/sys/signal.rs.orig	2024-02-18 16:20:52.047002882 +0000
+++ vendor/nix-0.26.2/src/sys/signal.rs
@@ -1069,7 +1069,7 @@ mod sigevent {
                 SigevNotify::SigevThreadId{..} => libc::SIGEV_THREAD_ID,
                 #[cfg(all(target_os = "linux", target_env = "uclibc"))]
                 SigevNotify::SigevThreadId{..} => libc::SIGEV_THREAD_ID,
-                #[cfg(any(all(target_os = "linux", target_env = "musl"), target_arch = "mips"))]
+                #[cfg(all(target_os = "linux", target_env = "musl", target_arch = "mips"))]
                 SigevNotify::SigevThreadId{..} => 4  // No SIGEV_THREAD_ID defined
             };
             sev.sigev_signo = match sigev_notify {
