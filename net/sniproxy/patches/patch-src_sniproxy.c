$NetBSD: patch-src_sniproxy.c,v 1.1 2019/01/11 23:09:54 schmonz Exp $

Support PKG_SYSCONFDIR.

--- src/sniproxy.c.orig	2018-12-06 04:14:58.000000000 +0000
+++ src/sniproxy.c
@@ -66,7 +66,7 @@ static struct ev_signal sigterm_watcher;
 
 int
 main(int argc, char **argv) {
-    const char *config_file = "/etc/sniproxy.conf";
+    const char *config_file = "@PKG_SYSCONFDIR@/sniproxy.conf";
     int background_flag = 1;
     rlim_t max_nofiles = 65536;
     int opt;
