$NetBSD: patch-host__applications_linux_apps_dtoverlay_dtoverlay__main.c,v 1.1 2016/11/01 16:45:28 skrll Exp $

--- host_applications/linux/apps/dtoverlay/dtoverlay_main.c.orig	2016-11-01 11:24:50.000000000 +0000
+++ host_applications/linux/apps/dtoverlay/dtoverlay_main.c
@@ -1006,8 +1006,10 @@ int seq_filter(const struct dirent *de)
     return (sscanf(de->d_name, "%d_", &num) == 1);
 }
 
-int seq_compare(const struct dirent **de1, const struct dirent **de2)
+int seq_compare(const void *d1, const void *d2)
 {
+    const struct dirent * const *de1 = d1;
+    const struct dirent * const *de2 = d2;
     int num1 = atoi((*de1)->d_name);
     int num2 = atoi((*de2)->d_name);
     if (num1 < num2)
