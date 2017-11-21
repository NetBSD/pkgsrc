$NetBSD: patch-src_daemon_collectd.c,v 1.1 2017/11/21 15:18:23 fhajny Exp $

Fix missing declaration.

--- src/daemon/collectd.c.orig	2017-11-18 09:03:27.350750556 +0000
+++ src/daemon/collectd.c
@@ -208,6 +208,7 @@ static int change_basedir(const char *or
 } /* static int change_basedir (char *dir) */
 
 #if HAVE_LIBKSTAT
+extern kstat_ctl_t *kc;
 static void update_kstat(void) {
   if (kc == NULL) {
     if ((kc = kstat_open()) == NULL)
