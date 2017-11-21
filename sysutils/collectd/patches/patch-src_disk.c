$NetBSD: patch-src_disk.c,v 1.3 2017/11/21 15:18:23 fhajny Exp $

Provide a port to NetBSD.

--- src/disk.c.orig	2017-11-18 09:03:27.354750373 +0000
+++ src/disk.c
@@ -135,6 +135,35 @@ static int numdisk;
 static int pnumdisk;
 /* #endif HAVE_PERFSTAT */
 
+#elif HAVE_SYSCTL && KERNEL_NETBSD
+
+#include <sys/sysctl.h>
+#include <sys/iostat.h>
+
+typedef struct diskstats {
+  char *name;
+
+  u_int poll_count;
+
+  derive_t read_ops;
+  derive_t write_ops;
+
+  derive_t read_bytes;
+  derive_t write_bytes;
+
+  derive_t avg_io_time;
+
+  struct io_sysctl stats;
+
+  struct diskstats *next;
+} diskstats_t;
+
+static diskstats_t *disklist;
+static struct io_sysctl *drives = NULL;
+static size_t ndrive = 0;
+
+/* #endif HAVE_SYSCTL && KERNEL_NETBSD */
+
 #else
 #error "No applicable input method."
 #endif
@@ -253,7 +282,33 @@ static int disk_init(void) {
       continue;
     ksp[numdisk++] = ksp_chain;
   }
-#endif /* HAVE_LIBKSTAT */
+/* #endif HAVE_LIBKSTAT */
+
+#elif HAVE_SYSCTL && KERNEL_NETBSD
+  int mib[3];
+  size_t size;
+
+  /* figure out number of drives */
+  mib[0] = CTL_HW;
+  mib[1] = HW_IOSTATS;
+  mib[2] = sizeof(struct io_sysctl);
+  if (sysctl(mib, 3, NULL, &size, NULL, 0) == -1) {
+    ERROR ("disk plugin: sysctl for ndrives failed");
+    return -1;
+  }
+  ndrive = size / sizeof(struct io_sysctl);
+
+  if (size == 0 ) {
+    ERROR ("disk plugin: no drives found");
+    return -1;
+  }
+  drives = (struct io_sysctl *)malloc(size);
+  if (drives == NULL) {
+    ERROR ("disk plugin: memory allocation failure");
+    return -1;
+  }
+
+#endif /* HAVE_SYSCTL && KERNEL_NETBSD */
 
   return 0;
 } /* int disk_init */
@@ -1017,7 +1072,129 @@ static int disk_read(void) {
                   1000000.0;
     disk_submit(stat_disk[i].name, "disk_time", read_time, write_time);
   }
-#endif /* defined(HAVE_PERFSTAT) */
+/* #endif defined(HAVE_PERFSTAT) */
+
+#elif HAVE_SYSCTL && KERNEL_NETBSD
+  int mib[3];
+  size_t size, i, nndrive;
+  diskstats_t *ds, *pre_ds;
+  char *output_name;
+
+  u_int64_t ops;
+  u_int64_t delta_t;
+
+  /* figure out number of drives */
+  mib[0] = CTL_HW;
+  mib[1] = HW_IOSTATS;
+  mib[2] = sizeof(struct io_sysctl);
+  if (sysctl(mib, 3, NULL, &size, NULL, 0) == -1) {
+    ERROR ("disk plugin: sysctl for ndrives failed");
+    return -1;
+  }
+  nndrive = size / sizeof(struct io_sysctl);
+
+  if (size == 0 ) {
+    ERROR ("disk plugin: no drives found");
+    return -1;
+  }
+  /* number of drives changed, reallocate buffer */
+  if (nndrive != ndrive) {
+    drives = (struct io_sysctl *)realloc(drives, size);
+    if (drives == NULL) {
+      ERROR ("disk plugin: memory allocation failure");
+      return -1;
+    }
+    ndrive = nndrive;
+  }
+
+  /* get stats for all drives */
+  mib[0] = CTL_HW;
+  mib[1] = HW_IOSTATS;
+  mib[2] = sizeof(struct io_sysctl);
+  if (sysctl(mib, 3, drives, &size, NULL, 0) == -1) {
+    ERROR ("disk plugin: sysctl for drive stats failed");
+    return -1;
+  }
+
+  for (i = 0; i < ndrive; i++) {
+
+    if (drives[i].type != IOSTAT_DISK)
+      continue;
+
+    /* find drive stats, if present */
+    for (ds = disklist, pre_ds = disklist;
+         ds != NULL;
+         pre_ds = ds, ds = ds->next) {
+      if (strcmp (drives[i].name, ds->name) == 0)
+        break;
+    }
+    if (ds == NULL) { /* not found; allocate & link in */
+      if ((ds = calloc(1, sizeof(diskstats_t))) == NULL)
+        continue;
+      if ((ds->name = strdup(drives[i].name)) == NULL) {
+        free(ds);
+        continue;
+      }
+      if (pre_ds == NULL)
+        disklist = ds;
+      else
+        pre_ds->next = ds;
+    }
+
+    ds->poll_count++;
+    if (ds->poll_count <= 2)
+    {
+      DEBUG ("disk plugin: (ds->poll_count = %i) <= "
+             "(min_poll_count = 2); => Not writing.",
+             ds->poll_count);
+      ds->stats = drives[i]; /* but save base values */
+      continue;
+    }
+    ds->read_ops    = drives[i].rxfer - ds->stats.rxfer;
+    ds->write_ops   = drives[i].wxfer - ds->stats.wxfer;
+    ds->read_bytes  = drives[i].rbytes - ds->stats.rbytes;
+    ds->write_bytes = drives[i].wbytes - ds->stats.wbytes;
+
+    /* Need this dance because of unsigned values... */
+    if (drives[i].time_usec < ds->stats.time_usec) {
+      delta_t = ((drives[i].time_sec - 1 -
+                  ds->stats.time_sec) * 1000) +
+                ((drives[i].time_usec + 1000000 -
+                  ds->stats.time_usec) / 1000);
+    } else {
+      delta_t = ((drives[i].time_sec -
+                  ds->stats.time_sec) * 1000) +
+                ((drives[i].time_usec -
+                  ds->stats.time_usec) / 1000);
+    }
+
+    ops = ds->read_ops + ds->write_ops;
+    if (ops == 0) {
+      DEBUG ("disk plugin: read + write ops == 0, "
+             "not writing");
+      continue;
+    }
+
+    ds->avg_io_time = delta_t / ops;
+
+    output_name = drives[i].name;
+
+    if ((ds->read_bytes != 0) || (ds->write_bytes != 0))
+      disk_submit (output_name, "disk_octets",
+                   ds->read_bytes, ds->write_bytes);
+
+    if ((ds->read_ops != 0) || (ds->write_ops != 0))
+      disk_submit (output_name, "disk_ops",
+                   ds->read_ops, ds->write_ops);
+
+    if (ds->avg_io_time != 0)
+      disk_submit (output_name, "disk_time",
+                   ds->avg_io_time, ds->avg_io_time);
+
+    ds->stats = drives[i];
+  }
+
+#endif /* HAVE_SYSCTL && KERNEL_NETBSD */
 
   return 0;
 } /* int disk_read */
