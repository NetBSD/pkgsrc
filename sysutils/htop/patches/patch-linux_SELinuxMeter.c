$NetBSD: patch-linux_SELinuxMeter.c,v 1.1 2021/03/15 22:23:59 fox Exp $

Disable SELinux stuff in NetBSD.

--- linux/SELinuxMeter.c.orig	2021-03-15 09:17:05.893787771 +0000
+++ linux/SELinuxMeter.c
@@ -12,8 +12,6 @@ in the source distribution for its full 
 #include <stdbool.h>
 #include <stdio.h>
 #include <unistd.h>
-#include <linux/magic.h>
-#include <sys/statfs.h>
 #include <sys/statvfs.h>
 
 #include "Macros.h"
@@ -29,27 +27,11 @@ static bool enabled = false;
 static bool enforcing = false;
 
 static bool hasSELinuxMount(void) {
-   struct statfs sfbuf;
-   int r = statfs("/sys/fs/selinux", &sfbuf);
-   if (r != 0) {
-      return false;
-   }
-
-   if ((uint32_t)sfbuf.f_type != (uint32_t)SELINUX_MAGIC) {
-      return false;
-   }
-
-   struct statvfs vfsbuf;
-   r = statvfs("/sys/fs/selinux", &vfsbuf);
-   if (r != 0 || (vfsbuf.f_flag & ST_RDONLY)) {
-      return false;
-   }
-
-   return true;
+   return false;
 }
 
 static bool isSelinuxEnabled(void) {
-   return hasSELinuxMount() && (0 == access("/etc/selinux/config", F_OK));
+   return false;
 }
 
 static bool isSelinuxEnforcing(void) {
