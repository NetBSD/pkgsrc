$NetBSD: patch-hier.c,v 1.1 2017/05/26 15:16:45 schmonz Exp $

PKG_SYSCONFDIR support.

--- hier.c.orig	2004-07-23 17:55:45.000000000 -0400
+++ hier.c
@@ -2,10 +2,10 @@
 
 void hier()
 {
-  c("/","etc","dnsroots.global",-1,-1,0644);
+  c(auto_home,"share/examples/djbdns","dnsroots.global",-1,-1,0644);
 
-  h(auto_home,-1,-1,02755);
-  d(auto_home,"bin",-1,-1,02755);
+  h(auto_home,-1,-1,0755);
+  d(auto_home,"bin",-1,-1,0755);
 
   c(auto_home,"bin","dnscache-conf",-1,-1,0755);
   c(auto_home,"bin","tinydns-conf",-1,-1,0755);
