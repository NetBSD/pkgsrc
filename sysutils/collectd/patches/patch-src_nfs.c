$NetBSD: patch-src_nfs.c,v 1.1 2020/10/24 22:39:45 wiz Exp $

Don't use undefined suppress_warning variable (see
https://github.com/collectd/collectd/pull/3495).

--- src/nfs.c.orig	2020-07-07 12:20:18.984988453 +0200
+++ src/nfs.c	2020-07-07 12:20:23.513661540 +0200
@@ -622,19 +622,14 @@ static int nfs_read(void) {
 
   /* NetBSD reports v2 statistics mapped to v3 and doen't yet support v4 */
   if (report_v2) {
-    if (!suppress_warning) {
-      WARNING(
-          "nfs plugin: NFSv2 statistics have been requested "
-          "but they are mapped to NFSv3 statistics in the kernel on NetBSD.");
-    }
+    WARNING("nfs plugin: NFSv2 statistics have been requested "
+            "but they are mapped to NFSv3 statistics in the kernel on NetBSD.");
     return 0;
   }
 
   if (report_v4) {
-    if (!suppress_warning) {
-      WARNING("nfs plugin: NFSv4 statistics have been requested "
-              "but they are not yet supported on NetBSD.");
-    }
+    WARNING("nfs plugin: NFSv4 statistics have been requested "
+            "but they are not yet supported on NetBSD.");
     return 0;
   }
 
