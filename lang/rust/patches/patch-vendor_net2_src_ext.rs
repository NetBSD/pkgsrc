$NetBSD: patch-vendor_net2_src_ext.rs,v 1.1 2020/07/08 14:46:14 jperkin Exp $

Support illumos.

--- vendor/net2/src/ext.rs.orig	2020-06-01 17:45:25.000000000 +0000
+++ vendor/net2/src/ext.rs
@@ -28,6 +28,7 @@ cfg_if! {
                  target_os = "netbsd",
                  target_os = "openbsd",
                  target_os = "solaris",
+                 target_os = "illumos",
                  target_env = "uclibc"))] {
         use libc::IPV6_JOIN_GROUP as IPV6_ADD_MEMBERSHIP;
         use libc::IPV6_LEAVE_GROUP as IPV6_DROP_MEMBERSHIP;
