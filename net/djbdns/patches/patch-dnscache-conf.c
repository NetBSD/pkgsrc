$NetBSD: patch-dnscache-conf.c,v 1.1 2017/05/26 15:16:45 schmonz Exp $

PKG_SYSCONFDIR support.

--- dnscache-conf.c.orig	2001-02-11 16:11:45.000000000 -0500
+++ dnscache-conf.c
@@ -89,13 +89,13 @@ int main(int argc,char **argv)
   if (chdir(auto_home) == -1)
     strerr_die4sys(111,FATAL,"unable to switch to ",auto_home,": ");
 
-  fdrootservers = open_read("/etc/dnsroots.local");
+  fdrootservers = open_read(PKG_SYSCONFDIR"/dnsroots.local");
   if (fdrootservers == -1) {
     if (errno != error_noent)
-      strerr_die2sys(111,FATAL,"unable to open /etc/dnsroots.local: ");
-    fdrootservers = open_read("/etc/dnsroots.global");
+      strerr_die4sys(111,FATAL,"unable to open ",auto_home,PKG_SYSCONFDIR"/dnsroots.local: ");
+    fdrootservers = open_read(PKG_SYSCONFDIR"/dnsroots.global");
     if (fdrootservers == -1)
-      strerr_die2sys(111,FATAL,"unable to open /etc/dnsroots.global: ");
+      strerr_die4sys(111,FATAL,"unable to open ",auto_home,PKG_SYSCONFDIR"/dnsroots.global: ");
   }
 
   init(dir,FATAL);
