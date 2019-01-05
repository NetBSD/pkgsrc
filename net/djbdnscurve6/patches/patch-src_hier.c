$NetBSD: patch-src_hier.c,v 1.1 2019/01/05 06:20:19 schmonz Exp $

PKG_SYSCONFDIR support.

--- src/hier.c.orig	2018-02-20 19:34:32.000000000 +0000
+++ src/hier.c
@@ -6,7 +6,7 @@ extern void c(const char* home,const cha
 
 void hier()
 {
-  c("/","etc","dnsroots.global",-1,-1,0644);
+  c(auto_home,"share/examples/djbdnscurve6","dnsroots.global",-1,-1,0644);
 
   h(auto_home,-1,-1,02755);
   d(auto_home,"bin",-1,-1,02755);
