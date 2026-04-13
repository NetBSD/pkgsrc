$NetBSD: patch-.._vendor_rattler__pty-0.2.9_src_unix_pty__process.rs,v 1.1 2026/04/13 16:07:24 pin Exp $

NetBSD uses the POSIX ptsname.

--- ../vendor/rattler_pty-0.2.9/src/unix/pty_process.rs.orig	2026-04-13 14:41:10.214991451 +0000
+++ ../vendor/rattler_pty-0.2.9/src/unix/pty_process.rs
@@ -27,6 +27,9 @@ use nix::pty::ptsname_r;
 #[cfg(target_os = "linux")]
 use nix::pty::ptsname_r;
 
+#[cfg(target_os = "netbsd")]
+use nix::pty::ptsname;
+
 /// Start a process in a forked tty so you can interact with it the same as you would
 /// within a terminal
 ///
@@ -112,7 +115,11 @@ impl PtyProcess {
         unlockpt(&master_fd)?;
 
         // on Linux this is the libc function, on OSX this is our implementation of ptsname_r
+        #[cfg(any(target_os = "linux", target_os = "android"))]
         let slave_name = ptsname_r(&master_fd)?;
+        // But NetBSD uses the POSIX ptsname instead
+        #[cfg(target_os = "netbsd")]
+        let slave_name = unsafe { ptsname(&master_fd) }?;
 
         // Get the current window size if it was not specified
         let window_size = opts.window_size.unwrap_or_else(|| {
