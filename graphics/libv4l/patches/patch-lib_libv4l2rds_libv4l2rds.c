$NetBSD: patch-lib_libv4l2rds_libv4l2rds.c,v 1.2 2022/05/17 11:55:23 jperkin Exp $

Support NetBSD and SunOS.

--- lib/libv4l2rds/libv4l2rds.c.orig	2020-05-14 09:23:59.000000000 +0000
+++ lib/libv4l2rds/libv4l2rds.c
@@ -14,7 +14,7 @@
 #include <sys/types.h>
 #include <sys/mman.h>
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -1039,10 +1039,12 @@ static time_t rds_decode_mjd(const struc
 	new_time.tm_year = y;
 	/* offset (submitted by RDS) that was used to compute the local time,
 	 * expressed in multiples of half hours, bit 5 indicates -/+ */
+#if !defined(__sun)
 	if (priv_state->utc_offset & 0x20)
 		new_time.tm_gmtoff = -offset * 1800;
 	else
 		new_time.tm_gmtoff = offset * 1800;
+#endif
 
 	/* convert tm struct to time_t value and return it */
 	return mktime(&new_time);
