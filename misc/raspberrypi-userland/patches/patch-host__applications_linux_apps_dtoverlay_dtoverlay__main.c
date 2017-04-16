$NetBSD: patch-host__applications_linux_apps_dtoverlay_dtoverlay__main.c,v 1.3 2017/04/16 19:25:25 skrll Exp $

--- host_applications/linux/apps/dtoverlay/dtoverlay_main.c.orig	2017-01-07 08:24:37.000000000 +0000
+++ host_applications/linux/apps/dtoverlay/dtoverlay_main.c
@@ -36,6 +36,10 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 
 #include <libfdt.h>
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 #include "dtoverlay.h"
 #include "utils.h"
 
@@ -1006,8 +1010,15 @@ int seq_filter(const struct dirent *de)
     return (sscanf(de->d_name, "%d_", &num) == 1);
 }
 
+#if defined (__NetBSD__) && __NetBSD_Version__-0 >= 799005100
 int seq_compare(const struct dirent **de1, const struct dirent **de2)
 {
+#else
+int seq_compare(const void *d1, const void *d2)
+{
+     const struct dirent * const *de1 = d1;
+     const struct dirent * const *de2 = d2;
+#endif
     int num1 = atoi((*de1)->d_name);
     int num2 = atoi((*de2)->d_name);
     if (num1 < num2)
