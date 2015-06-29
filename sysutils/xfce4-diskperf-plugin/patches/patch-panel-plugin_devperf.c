$NetBSD: patch-panel-plugin_devperf.c,v 1.2 2015/06/29 11:16:48 youri Exp $

Fix NetBSD support.
--- panel-plugin/devperf.c.orig	2014-09-11 13:45:46.000000000 +0000
+++ panel-plugin/devperf.c
@@ -335,21 +335,39 @@ int DevGetPerfData (const void *p_pvDevi
 	const char     *device = (const char *) p_pvDevice;
 	struct timeval tv;
 	size_t size, i, ndrives;
+#ifdef HW_DISKSTATS
 	struct disk_sysctl *drives, drive;
+#else
+	struct io_sysctl *drives, drive;
+#endif
 	int mib[3];
 
 	mib[0] = CTL_HW;
+#ifdef HW_DISKSTATS
 	mib[1] = HW_DISKSTATS;
 	mib[2] = sizeof(struct disk_sysctl);
+#else
+	mib[1] = HW_IOSTATS;
+	mib[2] = sizeof(struct io_sysctl);
+#endif
+
 	if (sysctl(mib, 3, NULL, &size, NULL, 0) == -1)
 		return(-1);
+#ifdef HW_DISKSTATS
 	ndrives = size / sizeof(struct disk_sysctl);
+#else
+	ndrives = size / sizeof(struct io_sysctl);
+#endif
 	drives = malloc(size);
 	if (sysctl(mib, 3, drives, &size, NULL, 0) == -1)
 		return(-1);
 
 	for (i = 0; i < ndrives; i++) {
+#ifdef HW_DISKSTATS
 		if (strcmp(drives[i].dk_name, device) == 0) {
+#else
+		if (strcmp(drives[i].name, device) == 0) {
+#endif
 			drive = drives[i];
 			break;
 		}
@@ -363,13 +381,18 @@ int DevGetPerfData (const void *p_pvDevi
 	gettimeofday (&tv, 0);
 	perf->timestamp_ns = (uint64_t)1000ull * 1000ull * 1000ull *
 		tv.tv_sec + 1000ull * tv.tv_usec;
-#if defined(__NetBSD_Version__) && (__NetBSD_Version__ < 106110000)
+#ifdef HW_DISKSTATS
+# if defined(__NetBSD_Version__) && (__NetBSD_Version__ < 106110000)
   /* NetBSD < 1.6K does not have separate read/write statistics. */
 	perf->rbytes = drive.dk_bytes;
 	perf->wbytes = drive.dk_bytes;
-#else
+# else
 	perf->rbytes = drive.dk_rbytes;
 	perf->wbytes = drive.dk_wbytes;
+# endif
+#else
+	perf->rbytes = drive.rbytes;
+	perf->wbytes = drive.wbytes;
 #endif
 
   /*
@@ -377,10 +400,18 @@ int DevGetPerfData (const void *p_pvDevi
    * time separatly.
    *                                              -- Benedikt
    */
+#ifdef HW_DISKSTATS
   perf->qlen = drive.dk_xfer;
 	perf->rbusy_ns = ((uint64_t)1000ull * 1000ull * 1000ull * drive.dk_time_sec
     + 1000ull * drive.dk_time_usec) / 2ull;
   perf->wbusy_ns = perf->rbusy_ns;
+#else
+  perf->qlen = drive.xfer;
+	perf->rbusy_ns = ((uint64_t)1000ull * 1000ull * 1000ull * drive.time_sec
+    + 1000ull * drive.time_usec) / 2ull;
+  perf->wbusy_ns = perf->rbusy_ns;
+
+#endif
 
 	return(0);
 }
