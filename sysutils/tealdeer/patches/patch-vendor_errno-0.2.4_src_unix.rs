$NetBSD: patch-vendor_errno-0.2.4_src_unix.rs,v 1.1 2020/03/19 19:43:52 bsiegert Exp $

Use the correct errno definition on NetBSD. Fixed upstream but not in a release
yet.

--- ../vendor/errno-0.2.4/src/unix.rs.orig	2018-07-10 05:44:23.000000000 +0200
+++ ../vendor/errno-0.2.4/src/unix.rs	2020-03-18 15:32:22.411361393 +0100
@@ -55,7 +55,7 @@
                    target_os = "ios",
                    target_os = "freebsd"),
                link_name = "__error")]
-    #[cfg_attr(any(target_os = "openbsd", target_os = "bitrig", target_os = "android"),
+    #[cfg_attr(any(target_os = "openbsd", target_os = "netbsd", target_os = "bitrig", target_os = "android"),
                link_name = "__errno")]
     #[cfg_attr(target_os = "solaris",
                link_name = "___errno")]
