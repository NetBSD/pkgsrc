$NetBSD: patch-src_dnsbl.cpp,v 1.1 2014/05/13 15:31:40 sborrill Exp $

Don't force configuration files to be relative to cwd

--- src/dnsbl.cpp.orig	2014-02-05 15:55:12.000000000 +0000
+++ src/dnsbl.cpp	2014-05-13 15:00:44.000000000 +0100
@@ -1625,7 +1625,7 @@
         snprintf(buf, sizeof(buf), "loading configuration generation %d", newc->generation);
         my_syslog(buf);
     }
-    if (load_conf(*newc, "dnsbl.conf")) {
+    if (load_conf(*newc, "@CONFDIR@/dnsbl.conf")) {
         newc->load_time = time(NULL);
         return newc;
     }
@@ -1700,7 +1700,7 @@
             else {
                 // failed to load new config
                 my_syslog("failed to load new configuration");
-                system("echo 'failed to load new dnsbl configuration from /etc/dnsbl' | mail -s 'error in /etc/dnsbl configuration' root");
+                system("echo 'failed to load new dnsbl configuration from @CONFDIR@' | mail -s 'error in @CONFDIR@ configuration' root");
                 // update the load time on the current config to prevent complaining every 3 minutes
                 dc.load_time = time(NULL);
             }
