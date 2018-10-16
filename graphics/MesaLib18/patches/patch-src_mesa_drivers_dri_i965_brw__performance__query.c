$NetBSD: patch-src_mesa_drivers_dri_i965_brw__performance__query.c,v 1.2 2018/10/16 15:21:20 jperkin Exp $

Prevents libdrm i915_drm.h header from being used.
libdrm 2.4.88 does not have certain symbols defined in its i915_drm.h.

--- src/mesa/drivers/dri/i965/brw_performance_query.c.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_performance_query.c
@@ -56,7 +56,7 @@
 #include <sys/ioctl.h>
 
 #include <xf86drm.h>
-#include <i915_drm.h>
+#include "drm-uapi/i915_drm.h"
 
 #include "main/hash.h"
 #include "main/macros.h"
@@ -1796,6 +1796,9 @@ enumerate_sysfs_metrics(struct brw_conte
    DIR *metricsdir = NULL;
    struct dirent *metric_entry;
    int len;
+#ifdef __sun
+   struct stat s;
+#endif
 
    len = snprintf(buf, sizeof(buf), "%s/metrics", brw->perfquery.sysfs_dev_dir);
    if (len < 0 || len >= sizeof(buf)) {
@@ -1812,10 +1815,18 @@ enumerate_sysfs_metrics(struct brw_conte
    while ((metric_entry = readdir(metricsdir))) {
       struct hash_entry *entry;
 
+#if defined(__sun)
+      stat(metric_entry->d_name, &s);
+      if ((s.st_mode != S_IFDIR &&
+           s.st_mode != S_IFLNK) ||
+          metric_entry->d_name[0] == '.')
+         continue;
+#else
       if ((metric_entry->d_type != DT_DIR &&
            metric_entry->d_type != DT_LNK) ||
           metric_entry->d_name[0] == '.')
          continue;
+#endif
 
       DBG("metric set: %s\n", metric_entry->d_name);
       entry = _mesa_hash_table_search(brw->perfquery.oa_metrics_table,
@@ -2057,6 +2068,9 @@ get_sysfs_dev_dir(struct brw_context *br
    DIR *drmdir;
    struct dirent *drm_entry;
    int len;
+#ifdef __sun
+   struct stat s;
+#endif
 
    brw->perfquery.sysfs_dev_dir[0] = '\0';
 
@@ -2088,9 +2102,16 @@ get_sysfs_dev_dir(struct brw_context *br
    }
 
    while ((drm_entry = readdir(drmdir))) {
+#if defined(__sun)
+      stat(drm_entry->d_name, &s);
+      if ((s.st_mode == S_IFDIR ||
+           s.st_mode == S_IFLNK) &&
+          strncmp(drm_entry->d_name, "card", 4) == 0)
+#else
       if ((drm_entry->d_type == DT_DIR ||
            drm_entry->d_type == DT_LNK) &&
           strncmp(drm_entry->d_name, "card", 4) == 0)
+#endif
       {
          len = snprintf(brw->perfquery.sysfs_dev_dir,
                         sizeof(brw->perfquery.sysfs_dev_dir),
