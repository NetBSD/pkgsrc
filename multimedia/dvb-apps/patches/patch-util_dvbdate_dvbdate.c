$NetBSD: patch-util_dvbdate_dvbdate.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- util/dvbdate/dvbdate.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/dvbdate/dvbdate.c
@@ -309,7 +309,12 @@ int atsc_scan_date(time_t *rx_time, unsi
  */
 int set_time(time_t * new_time)
 {
+#ifdef __NetBSD__
+	struct timeval new_tv = { .tv_sec = new_time, .tv_usec = 0 };
+	if (settimeofday(&new_tv, NULL)) {
+#else
 	if (stime(new_time)) {
+#endif
 		perror("Unable to set time");
 		return -1;
 	}
