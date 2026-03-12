$NetBSD: patch-src_enterprise_firewall_packetfilter_calls.rs,v 1.1 2026/03/12 12:20:32 adam Exp $

Fix build.

--- src/enterprise/firewall/packetfilter/calls.rs.orig	2026-03-12 11:54:06.302305708 +0000
+++ src/enterprise/firewall/packetfilter/calls.rs
@@ -195,6 +195,7 @@ impl RuleAddr {
             op,
             #[cfg(target_os = "macos")]
             _padding: [0; 3],
+            #[cfg(any(target_os = "freebsd", target_os = "macos"))]
             neg: 0,
         }
     }
