$NetBSD: patch-vendor_get_if_addrs-0.5.3_src_lib.rs,v 1.1 2021/02/21 18:53:05 pin Exp $

Add NetBSD support to archived upstream

--- ../vendor/get_if_addrs-0.5.3/src/lib.rs.orig	2018-06-21 12:35:24.000000000 +0000
+++ ../vendor/get_if_addrs-0.5.3/src/lib.rs
@@ -197,7 +197,7 @@ mod getifaddrs_posix {
     }
 
     #[cfg(
-        any(target_os = "freebsd", target_os = "ios", target_os = "macos", target_os = "openbsd")
+        any(target_os = "freebsd", target_os = "ios", target_os = "macos", target_os = "netbsd", target_os = "openbsd")
     )]
     fn do_broadcast(ifaddr: &posix_ifaddrs) -> Option<IpAddr> {
         sockaddr_to_ipaddr(ifaddr.ifa_dstaddr)
