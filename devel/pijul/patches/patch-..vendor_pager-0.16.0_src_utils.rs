$NetBSD: patch-..vendor_pager-0.16.0_src_utils.rs,v 1.1 2022/12/13 22:10:14 nikita Exp $

Original author: cs@FreeBSD.org

--- ../vendor/pager-0.16.0/src/utils.rs.orig	2021-07-20 20:40:27 UTC
+++ ../vendor/pager-0.16.0/src/utils.rs
@@ -66,7 +66,7 @@ pub(crate) fn execvpe(cmd: &OsString, envs: &[OsString
     };
     #[cfg(not(target_os = "macos"))]
     unsafe {
-        libc::execvpe(args[0], args.as_ptr(), envs.as_ptr())
+        libc::execve(args[0], args.as_ptr(), envs.as_ptr())
     };
 }
 
