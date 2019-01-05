$NetBSD: patch-src_dnscache-conf.c,v 1.1 2019/01/05 06:20:19 schmonz Exp $

PKG_SYSCONFDIR support.

--- src/dnscache-conf.c.orig	2018-08-06 09:49:44.000000000 +0000
+++ src/dnscache-conf.c
@@ -88,13 +88,13 @@ int main(int argc,char **argv)
   if (chdir(auto_home) == -1)
     logmsg(WHO,111,FATAL,B("unable to switch to: ",auto_home));
 
-  fdrootservers = open_read("/etc/dnsroots.local");
+  fdrootservers = open_read("@PKG_SYSCONFDIR@/dnsroots.local");
   if (fdrootservers == -1) {
     if (errno != ENOENT)
-      logmsg(WHO,111,FATAL,"unable to open /etc/dnsroots.local");
-    fdrootservers = open_read("/etc/dnsroots.global");
+      logmsg(WHO,111,FATAL,"unable to open @PKG_SYSCONFDIR@/dnsroots.local");
+    fdrootservers = open_read("@PKG_SYSCONFDIR@/dnsroots.global");
     if (fdrootservers == -1)
-      logmsg(WHO,111,FATAL,"unable to open /etc/dnsroots.global");
+      logmsg(WHO,111,FATAL,"unable to open @PKG_SYSCONFDIR@/dnsroots.global");
   }
 
   init(dir,WHO);
