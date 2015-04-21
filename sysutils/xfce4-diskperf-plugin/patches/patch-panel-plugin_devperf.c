$NetBSD: patch-panel-plugin_devperf.c,v 1.1 2015/04/21 08:56:40 jperkin Exp $

Add FreeBSD support and fix NetBSD support.
--- panel-plugin/devperf.c.orig	2015-02-09 23:25:33.000000000 +0000
+++ panel-plugin/devperf.c
@@ -225,6 +225,93 @@ int main ()
 
 	/**************************	Linux End	***************/
 
+#elif defined(__FreeBSD__)
+
+#include <sys/disk.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <sys/errno.h>
+#include <sys/resource.h>
+#include <sys/time.h>
+#include <devstat.h>
+#include <fcntl.h>
+#include <limits.h>
+#include <string.h>
+#include <syslog.h>
+#include <stdarg.h>
+
+#define MAXNAMELEN 256
+
+struct statinfo stats;
+struct devinfo dinfo;
+
+int DevPerfInit ()
+{
+	stats.dinfo = &dinfo;
+
+	return (0);
+}   
+
+int DevCheckStatAvailability(char const **strptr)
+{
+	return (0);
+}
+
+int DevGetPerfData (const void *p_pvDevice, struct devperf_t *perf)
+{
+	struct timeval tv;
+	struct timespec ts;
+	struct devstat dev;
+	kvm_t *kd = NULL;
+	int i, found = 0;
+	char *check_dev = (char *) p_pvDevice;
+
+	if(devstat_getdevs(kd, &stats) == -1) {
+		syslog(0, "DISKPERF: getdevs fail");
+	}
+
+	for(found = 0, i = 0; i < (stats.dinfo)->numdevs; i++) {
+		char dev_name[MAXNAMELEN];
+		dev = (stats.dinfo)->devices[i];
+		snprintf(dev_name, MAXNAMELEN-1, "%s%d",
+				dev.device_name, dev.unit_number);
+		if ((check_dev != NULL) && (strcmp(check_dev, dev_name) != 0))
+			continue;
+		else {
+			found = 1;
+			break;
+		}
+
+	}
+
+	if(check_dev != NULL && found) {
+		perf->wbytes = dev.bytes[DEVSTAT_WRITE];
+		perf->rbytes = dev.bytes[DEVSTAT_READ];
+		gettimeofday (&tv, 0);
+		perf->timestamp_ns = (uint64_t)1000ull * 1000ull * 1000ull *
+			tv.tv_sec + 1000ull * tv.tv_usec;
+		perf->qlen = dev.start_count - dev.end_count;
+		// I'm not sure about rbusy and wbusy calculation
+		bintime2timespec(&dev.busy_time, &ts);
+		perf->rbusy_ns = (uint64_t) ts.tv_nsec;
+		perf->wbusy_ns = perf->rbusy_ns;
+	}
+
+	return (0);
+}   
+
+#if 0				/* Standalone test purpose */
+int main ()
+{
+    struct devperf_t oPerf;
+    DevGetPerfData ((void*)"ada0", &oPerf);
+    printf ("%lu\t%lu\n", oPerf.rbytes, oPerf.wbytes);
+    return (0);
+}
+#endif
+
+
 
 #elif defined(__NetBSD__)
 	/**************************************************************/
@@ -251,21 +338,39 @@ int DevGetPerfData (const void *p_pvDevi
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
@@ -279,13 +384,18 @@ int DevGetPerfData (const void *p_pvDevi
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
@@ -293,10 +403,18 @@ int DevGetPerfData (const void *p_pvDevi
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
